// 	破坏球
#include <bits/stdc++.h>
#define int unsigned long long
int n, x;
std::vector<int> seq;

int sum(int i) { return seq[i - 1] + seq[i]; }

int deal(int j) {
  if (sum(j) <= x)
    return 0;
  int total = 0;
  if (seq[j - 1] > x) {
    total += seq[j - 1] - x;
    seq[j - 1] -= seq[j-1] - x;
  }
  if (seq[j] > x) {
    total += seq[j] - x;
    seq[j] -= seq[j] - x;
  }
  if (sum(j) <= x)
    return total;

  if (seq[j] != 0) {
    if (seq[j] - (sum(j) - x) >= 0) {
      total += sum(j) - x;
      seq[j] -= (sum(j) - x);
    } else {
      total += seq[j];
      seq[j] = 0;
    }
  }
  if (sum(j) <= x)
    return total;

  if (seq[j - 1] != 0) {
    if (seq[j - 1] - (sum(j) - x) >= 0) {
      total += sum(j) - x;
      seq[j - 1] -= (sum(j) - x);
    } else {
      total += seq[j - 1];
      seq[j - 1] = 0;
    }
  }
  return total;
}
#undef int
int main() {
#define int long long
  std::cin >> n >> x;
  seq.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> seq[i];
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans += deal(i);
  }
  std::cout << ans;
}