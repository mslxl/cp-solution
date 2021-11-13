#include <cstdio>
#include <functional>
typedef unsigned long long ll;

// const int maxn = (1e6 * 4);
const int maxn = 50;

ll tree[maxn] = {0};
ll tag_add[maxn] = {0};
ll tag_multi[maxn] = {1};

template <typename T>
T read_num() {
    T ret = 0;
    char c;
    while ((c = getchar()) && (c < '0' || c > '9'))
        ;
    do {
        ret = ret * 10 + (c - '0');
    } while ((c = getchar()) != EOF && (c >= '0' && c <= '9'));
    return ret;
}
// Get left node
inline ll lc(ll node) {
    return node * 2 + 1;
}
// Get right node
inline ll rc(ll node) {
    return node * 2 + 2;
}
inline void pull_up(ll node) {
    tree[node] = tree[lc(node)] + tree[rc(node)];
}
inline void push_down(ll node, ll start, ll end) {
    const ll mid = start + (end - start) / 2;
    tree[lc(node)] =
        tree[lc(node)] * tag_multi[node] + (mid - start + 1) * tag_add[node];
    tree[rc(node)] = tree[rc(node)] * tag_multi[node] +
                     (end - (mid + 1) + 1) * tag_add[node];

    tag_multi[lc(node)] *= tag_multi[node];
    tag_multi[rc(node)] *= tag_multi[node];

    tag_add[lc(node)] = tag_add[lc(node)] * tag_multi[lc(node)] + tag_add[node];
    tag_add[rc(node)] = tag_add[rc(node)] * tag_multi[rc(node)] + tag_add[node];

    tag_add[node] = 0;
    tag_multi[node] = 1;
}
void build_tree(ll* arr, ll node, ll start, ll end) {
    if (start == end) {
        tree[node] = arr[start - 1];
        return;
    }
    const auto left_node = lc(node);
    const auto right_node = rc(node);
    const ll mid = start + (end - start) / 2;
    build_tree(arr, left_node, start, mid);
    build_tree(arr, right_node, mid + 1, end);
    pull_up(node);
}
void edit_tree(ll node,
               ll start,
               ll end,
               ll left,
               ll right,
               std::function<void(ll&, ll, ll)> edit_function) {
    if (end < left || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        edit_function(tree[node], end - start + 1, node);
        return;
    }
    push_down(node, start, end);

    const auto left_node = lc(node);
    const auto right_node = rc(node);
    const ll mid = start + (end - start) / 2;
    edit_tree(left_node, start, mid, left, right, edit_function);
    edit_tree(right_node, mid + 1, end, left, right, edit_function);
    pull_up(node);
}
ll sum_tree(ll node, ll start, ll end, ll left, ll right) {
    if (end < left || right < start) {
        return 0;
    } else if (left <= start && end <= right) {
        return tree[node];
    }
    push_down(node, start, end);

    const auto left_node = lc(node);
    const auto right_node = rc(node);
    const ll mid = start + (end - start) / 2;

    ll left_sum = sum_tree(left_node, start, mid, left, right);
    ll right_sum = sum_tree(right_node, mid + 1, end, left, right);
    return left_sum + right_sum;
}

int main(int argc, char const* argv[]) {
    ll n = read_num<ll>(), m = read_num<ll>(), p = read_num<ll>();
    ll* init = new ll[n];
    for (ll i = 0; i < n; i++)
        init[i] = read_num<ll>();
    build_tree(init, 0, 1, n);
    delete[] init;
    ll x, y, op;
    ll k;
    while (m--) {
        op = read_num<ll>();
        x = read_num<ll>();
        y = read_num<ll>();
        if (op == 1) {
            // multiply [k]
            k = read_num<ll>();
            edit_tree(0, 1, n, x, y,
                      [k](ll& basis_val, ll num, ll node) -> void {
                          basis_val *= k;
                          // Save lazy tag
                          tag_multi[node] *= k;
                          tag_add[node] *= k;
                      });

        } else if (op == 2) {
            // plus [k]
            k = read_num<ll>();
            edit_tree(0, 1, n, x, y,
                      [k](ll& basis_val, ll num, ll node) -> void {
                          basis_val += (k * num);
                          tag_add[node] += k;
                      });

        } else if (op == 3) {
            ll sum = sum_tree(0, 1, n, x, y);
            printf("%lld\n", sum % p);
        }
    }
    return 0;
}
