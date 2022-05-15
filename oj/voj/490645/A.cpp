#include <bits/stdc++.h>
const int maxn = 1e5;
int seq[maxn];
void solve() {
  int max = 0, max_idx = -1;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> seq[i];
    if (seq[i] > max) {
      max = seq[i];
      max_idx = i;
    }
  }

  if(max_idx == n - 1 || max_idx == 0){
    std::cout << "No\n";
    return;
  }

  int last_check = seq[0];
  for (int i = 1; i <= max_idx; i++) {
    if (seq[i] > last_check) {
      last_check = seq[i];
    } else {
      std::cout << "No\n";
      return;
    }
  }
  last_check = seq[n-1];
  for(int i = n-2; i > max_idx; i--){
    if (seq[i] > last_check) {
      last_check = seq[i];
    } else {
      std::cout << "No\n";
      return;
    }
  }
  std::cout << "Yes\n";
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}