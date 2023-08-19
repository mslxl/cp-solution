#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005][1005];
unordered_map<string, vector<int>> mp;
int main() {
  cin >> n >> m;
  string s;
  s.resize(m);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      cin >> a[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      s[j - 1] = a[j][i];
    mp[s].push_back(i);
  }
  pair<int, int> p = make_pair(n + 1, n + 1);
  for (auto &it : mp)
    if (it.second.size() >= 2)
      p = min(p, make_pair(it.second[0], it.second[1]));
  if (p.first == n + 1)
    puts("-1");
  else
    printf("%d %d", p.first, p.second);
  return 0;
}