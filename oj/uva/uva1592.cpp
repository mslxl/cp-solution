#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
int n, m, id, v[10010][11];  // v存储矩阵位置中字符串对应的ID值
char ch;
bool tf;
string str;
map<string, int> mp;
map<ll, int> q;
int main() {
    while (cin >> n >> m) {
        mp.clear();
        id = 0;
        getchar();  //在此处初始化
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                str.clear();
                while (1) {
                    ch = getchar();
                    if (ch == ',' || ch == '\n' || ch == '\r' || ch == EOF)
                        break;
                    str.push_back(ch);
                }
                if (mp.count(str))
                    v[i][j] = mp[str];
                else
                    v[i][j] = mp[str] = ++id;
            }  //输入
        id++;
        tf = false;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j < i; j++) {
                q.clear();
                for (int k = 1; k <= n && !tf; k++)
                    if (q.count((ll)v[k][i] * id + v[k][j])) {
                        printf("NO\n");
                        printf("%d %d\n%d %d\n", q[(ll)v[k][i] * id + v[k][j]],
                               k, j, i);
                        tf = true;
                    } else
                        q[(ll)v[k][i] * id + v[k][j]] = k;
                if (tf)
                    break;
            }
        if (!tf)
            printf("YES\n");
    }
    return 0;
}