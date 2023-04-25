#include <bits/stdc++.h>
using ll = long long;
std::vector<std::string> map(30);
bool vis[30][60];
ll cache[30][60];

ll dfs(int y, int x) {
  if (y == 29 && x == 59) {
    return map[y][x] - '0';
  }
  if(vis[y][x]){
    return cache[y][x];
  }else{
    ll ans = 0;
    if(y < 29){
      ans = std::max(ans, dfs(y+1, x));
    }
    if(x < 59){
      ans = std::max(ans, dfs(y, x+1));
    }
    ans += map[y][x] - '0';
    cache[y][x] = ans;
    vis[y][x] = true;
    return cache[y][x];
  }
}

int main() {
  for (auto &l : map) {
    std::getline(std::cin, l);
  }
  cache[29][59] = map[29][59] - '0';
  vis[29][59] = true;
  std::cout << dfs(0, 0);
  
  std::string l;
  std::getline(std::cin, l);
}