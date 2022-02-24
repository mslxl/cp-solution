#include <bits/stdc++.h>
int N, C;
long long ans = 0;
int main() {
  std::cin >> N >> C;
  std::vector<int> seq(N);
  for (int i = 0; i < N; i++) {
    std::cin >> seq[i];
  }
  std::sort(seq.begin(), seq.end());

  long long l = 0, r_start = l + 1, r_end, l_end;

  while (l < N) {
    l_end = l;
    while (l_end + 1 < N && seq[l_end + 1] == seq[l_end])
      l_end++;

    while (r_start + 1 < N && seq[r_start] - seq[l] < C)
      r_start++;
    // std::cout << "l is: " << l << std::endl;
    // std::cout << "first r_start: " << r_start << std::endl;
    r_end = r_start;
    while (r_end + 1 < N && seq[r_end + 1] == seq[r_end])
      r_end++;
    // std::cout << "first r_end: " << r_end << std::endl;
    // std::cout << "minus result: " << seq[r_start] - seq[l] << std::endl;
    if (r_start < N && seq[r_start] - seq[l] == C) {
      ans += (r_end - r_start + 1) * (l_end - l + 1);
    }
    l = l_end + 1;
    r_start = r_end + 1;
  }

  std::cout << ans;

  return 0;
}
