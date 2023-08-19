#include <bits/stdc++.h>

int main() {
  std::string tok;
  std::stack<bool> and_fst;
  std::stack<bool> or_fst;

  while (std::cin >> tok) {
    if (tok == "true") {
      and_fst.push(true);
      or_fst.push(true);
    } else if (tok == "false") {
      and_fst.push(false);
      or_fst.push(false);
    } else if (tok == "or") {
      std::cin >> tok;
      bool ans = or_fst.top() || (tok == "true");
      and_fst.push(tok=="true");
      or_fst.pop(), or_fst.push(ans);
    } else if (tok == "and") {
      std::cin >> tok;
      bool ans = and_fst.top() && (tok == "true");
      or_fst.push(tok == "true");
      and_fst.pop(), and_fst.push(ans);
    }
  }

  bool ans1 = and_fst.top(), ans2 = or_fst.top();
  and_fst.pop(), or_fst.pop();
  while (!and_fst.empty()) {
    ans1 = ans1 || and_fst.top();
    and_fst.pop();
  }

  while (!or_fst.empty()) {
    ans2 = ans2 && or_fst.top();
    or_fst.pop();
  }
  std::cout << (ans1 ? "true" : "false") << "\n";
  std::cout << (ans2 ? "true" : "false");
}