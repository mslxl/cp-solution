#include <bits/stdc++.h>
#include <limits>

void solve();

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2);
  std::vector<int> f(n + 2);
  std::map<int, int> lst;

  for (int i = 1; i <= n; i++) std::cin >> a[i];

  for (int i = 1; i <= n; i++) {
    f[i] = (i - lst[a[i]] > 1) ? (f[lst[a[i]]] + 1) : f[lst[a[i]]];
    lst[a[i]] = i;
  }

  int min = std::numeric_limits<int>::max(), num = 0;
  for (auto l : lst) {
    int c = lst[l.first] == n ? f[lst[l.first]] : (f[lst[l.first]] + 1);
    if (c < min) {
      num = l.first;
      min = c;
    }
  }
  std::cout << num << " " << min << "\n";
}