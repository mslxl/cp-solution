#include <bits/stdc++.h>
#include <cctype>
#define YES                                                                    \
  std::cout << "Same.\n";                                                      \
  continue
#define NO                                                                     \
  std::cout << "Different.\n";                                                 \
  continue
int main() {
  std::string a, b;
  while (std::cin >> a >> b) {
    if (a.size() != b.size()) {
      NO;
    }

    for (auto &ch : a)
      if (std::isalpha(ch))
        ch = std::tolower(ch);
    for (auto &ch : b)
      if (std::isalpha(ch))
        ch = std::tolower(ch);

    if (a == b) {
      YES;
    } else {
      NO;
    }
  }
  return 0;
}