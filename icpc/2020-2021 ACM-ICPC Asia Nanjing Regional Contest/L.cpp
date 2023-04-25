// clang-format off
#include <bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;
using ld = long double;

template<typename T>
inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x) {
    char c;
    T f = 1;
    while (!isdigit(c = getchar())) if (c == '-')f = -1;
    x = (c & 15);
    while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
    x *= f;
}

template<typename T, typename... A>
inline void read(T &value, A &..._t) { read(value), read(_t...); }

void solve(const std::size_t testcase);

#define rep(NAME, MAX) for(decltype(MAX) NAME = 0; NAME < MAX; NAME++)
#define rep1(NAME, MAX) for(decltype(MAX) NAME = 1; NAME <= MAX; NAME++)
#define repv0(NAME, START) for(decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for(decltype(START) NAME = START; NAME >= 1; NAME--)

int main() {
    std::size_t t = 1;
    read(t);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    rep1(i, t) solve(t);
    return 0;
}
// clang-format on
#define int ll

const int INF = std::numeric_limits<int>::max();

const int maxn = 1e5 + 17;
int n, m;
int blue[maxn], red[maxn];

void solve(const std::size_t testcase) {
    read(n, m);
    rep1(i, n) read(red[i]);
    rep1(i, m) read(blue[i]);
    std::sort(red + 1, red + n + 1);
    std::sort(blue + 1, blue + m + 1);
    blue[m + 1] = INF;
    ll ans = 0;
    rep(i, m + 1) {
        int l = std::upper_bound(red + 1, red + n + 1, blue[i]) - (red + 1) + 1;
        int r = std::lower_bound(red + 1, red + n + 1, blue[i + 1]) - (red + 1) + 1 - 1;
        if (red[l] <= blue[i] || red[r] >= blue[i + 1]) continue; // for duplicated element
        ans = std::max(ans, r - l + 1);
    }
    if (ans != 0) {
        std::cout << ans << "\n";
    } else {
        std::cout << "Impossible\n";
    }
}
