#include <algorithm>
#include <iostream>
typedef long long ll;
ll N, C;
ll *num = nullptr;
int main() {
  std::cin >> N >> C;
  num = new ll[N + 10];
  for (int i = 0; i < N; i++) {
    std::cin >> num[i];
  }
  std::sort(num, num + N);

  int split = N - 2;

  std::cout << "array is [";
  for(ll *i = num; i != (num+N); i++){
    std::cout << *i << ',';
  }
  std::cout << "\b], C = " << C << std::endl;

  while (num[N - 1] - num[split] < C && split >= 0)
    split--;


  std::cout << "split at idx " << split << " , where value is " << num[split]
            << std::endl;
  if (split == -1) {
    std::cout << 0;
    return 0;
  }

  int l = split, r = N - 1;
  int ans = 0;

  ll value = 0x66ccff;
  while (l >= 0) {
    value = num[r] - num[l];
    std::cout << num[r] << " - " << num[l] << " = " << value << " <=> " << C
              << std::endl;
    if (value == C) {
      ans++;
      if (l != 0) {
        l--;
      } else {
        r--;
      }
    } else if (value < C) {
        l--;
    } else {
      r--;
    }
  }
  std::cout << ans;
  return 0;
}
