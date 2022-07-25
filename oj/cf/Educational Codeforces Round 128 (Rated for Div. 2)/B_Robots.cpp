#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#undef Local
#endif
#ifdef Local
#define tout \
  if (1)     \
  std::cerr
#else
#define tout \
  if (0)     \
  std::cerr
#endif
using ll = long long;
using ull = unsigned long long;
#define rep(i, s, e) for (int i = s; i < e; i++)
#define fors(i, s, e) rep(i, s, e + 1)

void solve() {
  int r, c;
  std::cin >> r >> c;
  std::cin.get();
  std::vector<std::string> map;
  rep(i, 0, r) {
    std::string l;
    std::getline(std::cin, l);
    bool emptyLine = true;
    for(const char &c:l){
      if(c == 'R') {
        emptyLine = false;
        break;
      }
    }
    if(emptyLine) continue;
    map.push_back(l);
  }
  rep(cc, 0, c){
    rep(cr, 0, map.size()){
      char ch = map[cr][cc];
      if(ch == 'R' && cr != 0){
        std::cout << "NO" << std::endl;
        return;
      } else if(ch == 'R' && cr == 0){
        std::cout << "YES" << std::endl;
        return;
      }
    }
  }
  assert(false);
}

int main() {
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
