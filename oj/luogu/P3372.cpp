/**
 *  seg tree template
 */
#include <cstdio>
#define _GLIBCXX_DEBUG
typedef long long ll;

const int N = (1e7 + 5) * 4;
ll tree[N] = {0};
ll tag[N] = {0};

inline void pull_up(ll node) {
  tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

inline void push_down(ll node, ll start, ll end) {
  if (tag[node]) {
    const ll left_node = node * 2 + 1;
    const ll right_node = node * 2 + 2;
    const ll mid = (start + end) / 2;

    tag[left_node] += tag[node];
    tag[right_node] += tag[node];

    tree[left_node] += (mid - start + 1) * tag[node];
    tree[right_node] += (end - (mid + 1) + 1) * tag[node];

    tag[node] = 0;
  }
}

void build_tree(ll array[], ll node, ll start, ll end) {
  if (start == end) {
    tree[node] = array[start - 1];
    return;
  }
  const ll mid = (start + end) / 2;
  const ll left_node = node * 2 + 1;
  const ll right_node = node * 2 + 2;
  build_tree(array, left_node, start, mid);
  build_tree(array, right_node, mid + 1, end);
  pull_up(node);
}

void inc_tree_node(ll node, ll start, ll end, ll l, ll r, ll val) {
  if (end < l or start > r) {
    return;
  } else if (l <= start and end <= r) {
    tree[node] += (end - start + 1) * val;
    tag[node] += val;
    return;
  }
  push_down(node, start, end);
  const ll mid = (start + end) / 2;
  const ll left_node = node * 2 + 1;
  const ll right_node = node * 2 + 2;
  inc_tree_node(left_node, start, mid, l, r, val);
  inc_tree_node(right_node, mid + 1, end, l, r, val);
  pull_up(node);
}

long long sum_tree(ll node, ll start, ll end, ll left, ll right) {
  if (end < left or start > right) {
    return 0;
  } else if (start >= left and end <= right) {
    return tree[node];
  }

  push_down(node, start, end);
  const ll mid = (start + end) / 2;
  const ll left_node = node * 2 + 1;
  const ll right_node = node * 2 + 2;
  ll left_sum = sum_tree(left_node, start, mid, left, right);
  ll right_sum = sum_tree(right_node, mid + 1, end, left, right);
  return left_sum + right_sum;
}

template <typename T> inline T read_num() {
  T val = 0;
  char c;
  while ((c = getchar()) and (c < '0' or c > '9')) {
    // Skip non-number character
  };
  do {
    val = val * 10 + (c - '0');
  } while ((c = getchar()) and c >= '0' and c <= '9');
  return val;
}

int main(int argc, char const *argv[]) {
  int n, m;
  n = read_num<int>();
  m = read_num<int>();
  ll *initial = new ll[n];
  for (int i = 0; i < n; i++) {
    initial[i] = read_num<ll>();
  }
  build_tree(initial, 0, 1, n);
  delete[] initial;
  int op;
  ll x, y, k;
  while (m--) {
    op = read_num<int>();
    x = read_num<ll>();
    y = read_num<ll>();
    if (op == 1) {
      k = read_num<ll>();
      inc_tree_node(0, 1, n, x, y, k);
    } else {
      printf("%lld\n", sum_tree(0, 1, n, x, y));
    }
  }
  return 0;
}
