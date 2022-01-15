#include <algorithm>
#include <exception>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>

std::unordered_map<int, std::set<int>**> eq;  // equal
std::unordered_map<int, std::set<int>**> ne;  // not equal
std::queue<std::set<int>*> pool;              // for recycling memory

#define return_kaj_throw(t)             \
    int _trash;                         \
    for (int i = 0; i < (t * 3); i++) { \
        std::cin >> _trash;             \
    }                                   \
    return;

bool is_valid(int a, int b, bool is_eq) {
    bool valid = true;
    if (eq.count(a)) {
        auto& st = **eq[a];
        if (st.count(b)) {
            valid = valid && is_eq;
        }
    } else if (ne.count(a)) {
        auto& st = **ne[a];
        if (st.count(b)) {
            valid = valid && !is_eq;
        }
    }
    if (eq.count(b)) {
        auto& st = **eq[b];
        if (st.count(a)) {
            valid = valid && is_eq;
        }
    } else if (ne.count(b)) {
        auto& st = **ne[b];
        if (st.count(a)) {
            valid = valid && !is_eq;
        }
    }
    return valid;
}

void link_eq(int a, int b) {
    if (eq.count(a) && eq.count(b)) {
        auto set_a = **eq[a], set_b = **eq[b];
        std::set_union(set_a.begin(), set_a.end(), set_b.begin(), set_b.end(),
                       std::inserter(set_a, set_a.begin()));
        *eq[b] = *eq[a];
    } else if (eq.count(a)) {
        auto& st = **eq[a];
        st.insert(b);
        eq[b] = eq[a];
    } else if (eq.count(b)) {
        auto& st = **eq[b];
        st.insert(a);
        eq[a] = eq[b];
    } else {
        auto st = new std::set<int>*(new std::set<int>());
        (*st)->insert(a);
        (*st)->insert(b);
        eq[b] = eq[a] = st;
        pool.push(*st);
    }
}

void link_ne(int a, int b) {
    if (ne.count(a)) {
        auto& st = **ne[a];
        st.insert(b);
        ne[b] = ne[a];
    } else if (ne.count(b)) {
        auto& st = **ne[b];
        st.insert(a);
        ne[a] = ne[b];
    } else {
        auto st = new std::set<int>*(new std::set<int>());
        (*st)->insert(a);
        (*st)->insert(b);
        ne[b] = ne[a] = st;
        pool.push(*st);
    }
}

inline void clear_map(std::unordered_map<int, std::set<int>**>& mp) {
    for (const auto& pr : mp) {
        delete pr.second;
    }
    mp.clear();
}

void clear() {
    clear_map(ne);
    clear_map(eq);

    if (!pool.empty()) {
        while (!pool.empty()) {
            auto ptr = pool.front();
            pool.pop();
            delete ptr;
        }
    }

#ifdef DEBUG
    std::cout << "Recycle memory" << std::endl;
#endif
}

void solve() {
    int num;
    std::cin >> num;
    while (num--) {
        int i, j, e;
        std::cin >> i >> j >> e;
        if (e == 1) {
            if (!is_valid(i, j, true)) {
                std::cout << "NO" << std::endl;
                return_kaj_throw(num);
            }
            link_eq(i, j);
        } else {
            if (!is_valid(i, j, false)) {
                std::cout << "NO" << std::endl;
                return_kaj_throw(num);
            }
            link_ne(i, j);
        }
    }
    std::cout << "YES" << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
        clear();
#ifdef DEBUG
        std::cout << "OTHER ONE" << std::endl;
#endif
    }

    return 0;
}
