#include <bits/stdc++.h>
#include <queue>

std::string A, B;

using pss = std::pair<std::string, std::string>;
using psi = std::pair<std::string, int>;
std::vector<pss> trans;

int main() {
  std::cin >> A >> B;
  do {
    std::string u, v;
    while (std::cin >> u >> v) {
      trans.push_back({u, v});
    }
  } while (0);

  std::queue<std::string> que;
  std::map<std::string, int> dis;
  que.push({A, 0});
  while (!que.empty()) {
    auto u = que.front();
    que.pop();
    if (dis[u] > 10)
      continue;

    if (u == B) {
      std::cout << dis[u];
      return 0;
    }

    for (auto rule : trans) {
      auto s = -1;

      while ((s = u.find(rule.first, s+1)) != std::string::npos) {
        std::string v(u);
        v.replace(s, rule.first.size(), rule.second);
        if (dis.count(v))
          continue;
        dis[v] = dis[u] + 1;
        que.push(v);
      }
    }
  }
  std::cout << "NO ANSWER!";
  return 0;
}