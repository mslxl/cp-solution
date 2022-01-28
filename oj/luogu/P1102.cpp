#include <iostream>
#include <vector>
const int maxn = 3000;
int N, C;
int ans = 0;
int main() {
  std::cin >> N >> C;
  std::vector<int> num(N);
  int n;
  for (int i = 0; i < N; i++) {
    std::cin >> n;
    num.insert(n);
  }
  for (auto &i : num) {
    if (num.count(C + i)) {
      ans++;
    }
  }
  std::cout << ans;
  return 0;
}
