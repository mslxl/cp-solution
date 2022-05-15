#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = s; i < e; i++)
void solve() {
  int n, b;
  std::cin >> n >> b;
  bool flag = false;
  rep(i, 0, n) {
    int a;
    std::cin >> a;
    if ((a + b) % 7 == 0) {
      flag = true;
    }
  }
  std::cout << (flag ? "Yes" : "No") << std::endl;
}
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}