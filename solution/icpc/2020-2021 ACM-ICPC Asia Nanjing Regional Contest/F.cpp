#include<bits/stdc++.h>

using ld =  double;
using ll =  long;


ld qpow(ld a, ll b)
{
    ld ans = 1;
    ld base = a;
    while(b > 0)
    {
        if(b & 1)
            ans *= base;

        base *= base;
        b >>= 1;
    }
    return ans;
}
ld n, m, p;

ld calc(ll k) {
    return  (k * n + m) / (1 - qpow(1 - p, k));
}

void solve() {
    std::cin >> n >> m >> p;
    p /= 1e4;
    ll l = 1, r = std::numeric_limits<int>::max() / 3 * 2;
    while (l < r) {
        ll mid1 = l + (r - l) / 3;
        ll mid2 = r - (r - l) / 3;
        if(calc(mid1) < calc(mid2)) r = mid2 - 1;
        else l = mid1 + 1;
    }
    std::cout << calc(l) << "\n";
}

int main() {
    int T;
    std::cin >> T;
    std::cout << std::setprecision(5) << std::fixed;
    while (T--) {
        solve();
    }
}
