#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = s; i < e; i++)

const short flag_even = 0, flag_odd = 1;

using ul = unsigned long long;
void solve() {
  ul a, b;
  std::cin >> a >> b;

  assert(a <= b);
  int num_even = 0, num_odd = 0;

  if (b - a < 10) {
    rep(i, a, b + 1) {
        if(i % 3 == 0){
            num_even++;
        }else{
            num_odd++;
        }
    }
  } else {
    if (a % 3 == 0) {
      num_even++;
    } else {
      num_odd += (3 - a % 3);
    }
    if (b % 3 == 0) {
      num_even++;
      num_odd += 2;
    } else {
      num_odd += b % 3;
    }
  }
  std::cout << (num_odd % 2 == 0 ? flag_even : flag_odd) << std::endl;
}
int main() {
  int T;
  std::cin >> T;
  while (T--) {
      solve();
  }

  return 0;
}