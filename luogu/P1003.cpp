#include <iostream>

const int maxn = 10001;
int a[maxn][4] = {0};
int n;

int main() {
    using std::cin;
    int sx, sy;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }
    cin >> sx >> sy;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int stx = a[i][0] + a[i][2];
        int sty = a[i][1] + a[i][3];
        if (sx >= a[i][0] && sx <= stx && sy >= a[i][1] && sy <= sty)
            ans = i;
    }
    if (ans == 0)std::cout << -1;
    else std::cout << ans;
    return 0;
}