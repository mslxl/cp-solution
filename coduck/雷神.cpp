#include <bits/stdc++.h>
const int maxn = 3e5 + 17;

int vis[maxn];
int main() {
  int n, q;
  std::cin >> n >> q;
  std::unordered_map<int, std::queue<int>> msg;
  int cnt = 0, ans = 0;

  for (int i = 0; i < q; i++) {
    int op, x;
    std::cin >> op >> x;

    if (op == 1) {
      cnt++;
      msg[x].push(cnt);
      msg[0].push(cnt);
      vis[cnt] = 1;
      ans++;
    } else if (op == 2) {
      while (!msg[x].empty()) {
        int id = msg[x].front();
        if (vis[id]) {
          ans--;
          vis[id] = 0;
        }
        msg[x].pop();
      }
    } else if (op == 3) {
      while(!msg[0].empty() && msg[0].front() <= x){
        int id = msg[0].front();
        if(vis[id]){
          ans--;
          vis[id] = 0;
        }
        msg[0].pop();
      }
    }

    std::cout << ans << "\n";
  }
}