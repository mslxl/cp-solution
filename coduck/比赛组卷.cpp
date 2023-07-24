#include <bits/stdc++.h>

int n, k;

std::set<int> a, s;

int main() {
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    a.insert(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    if (a.count(x)) {
      s.insert(x);
    }
  }
  std::cout << s.size() << "\n";
  if (!s.empty())
    for (auto i : s)
      std::cout << i << " ";

  return 0;
}