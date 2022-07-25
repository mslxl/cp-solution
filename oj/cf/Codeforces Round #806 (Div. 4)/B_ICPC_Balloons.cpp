#include <bits/stdc++.h>
int main() {
  int T,Q;
  std::cin >> T;
  while (T--) {
    std::string c;
    std::cin >> Q >> c;
    std::set<char> st(c.begin(), c.end());
    std::cout << st.size() + Q << std::endl;
  }
  return 0;
}