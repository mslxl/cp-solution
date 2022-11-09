#include <bits/stdc++.h>
#include <limits>
#include <numeric>
using ll = int;
using ull = int;

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    long long value;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
      std::cin >> value;
      sum+= value;
    }
    std::cout << std::abs(sum) << std::endl;
   
  }
}