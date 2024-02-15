#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            string st;
            cin >> st;
            for (int j = 0; j < n; j++) {
                a[i][j] = st[j];
            }
        }

        int ans = 0;
        vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> mark(n + 2, vector<int>(n + 1, 0));
        vector<vector<int>> neg(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mark[i][j] != 0) {
                    arr[i][j] += mark[i][j];
                    int st = max(j - 1, 0);
                    int en = min(n, j + 1);
                    mark[i + 1][st] += mark[i][j];
                }
                if (neg[i][j] != 0) {
                    arr[i][j] -= neg[i][j];
                    int st = max(j - 1, 0);
                    int en = min(n, j + 1);
                    neg[i + 1][en] += neg[i][j];
                }
            }
            for (int j = 1; j < n; j++) {
                arr[i][j] += arr[i][j - 1];
            }
            for (int j = 0; j < n; j++) {
                if (arr[i][j] % 2 == 1) {
                    if (a[i][j] == '0') {
                        a[i][j] = '1';
                    } else {
                        a[i][j] = '0';
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '2') {
                    ans += 1;
                    int st = max(j - 1, 0);
                    int en = min(n, j + 1 + 1);
                    mark[i + 1][st] += 1;
                    neg[i + 1][en] += 1;
                }
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}