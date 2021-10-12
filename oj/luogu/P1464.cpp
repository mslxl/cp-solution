#include <iostream>
#include <cstdio>
#include <cstring>

typedef long long ll;

ll table[21][21][21];

ll w(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    } else if (a > 20 || b > 20 || c > 20) {
        return 1048576;
    } else if (table[a][b][c] != 0) {
        return table[a][b][c];
    } else if (a < b && b < c) {
        table[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
        table[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    return table[a][b][c];
}

int main() {
    ll a, b, c;
    memset(table, 0, sizeof(table));
    while (std::cin >> a >> b >> c && (a != -1 || b != -1 || c != -1)) {
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}