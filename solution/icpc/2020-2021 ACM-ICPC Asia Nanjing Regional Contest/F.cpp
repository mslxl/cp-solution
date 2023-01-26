#include<bits/stdc++.h>

using ld =  double;
using ll =  long;


ld qpow(ld a, ll b)//是求a的b次方
{
    ld ans = 1;
    ld base = a;//ans为答案，base为a^(2^n)
    while(b > 0)//b是一个变化的二进制数，如果还没有用完
    {
        if(b & 1)//&是位运算，b&1表示b在二进制下最后一位是不是1，如果是：
            ans *= base;//把ans乘上对应的a^(2^n)

        base *= base;//base自乘，由a^(2^n)变成a^(2^(n+1))
        b >>= 1;//位运算，b右移一位，如101变成10（把最右边的1移掉了），10010变成1001。现在b在二进制下最后一位是刚刚的倒数第二位。结合上面b & 1食用更佳
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