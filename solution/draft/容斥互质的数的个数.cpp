#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, std::vector<T>>::type
prime(T num) {
  std::vector<T> seq;
  for (T i = 2; i * i < num; i++) {
    if (num % i == 0) {
      seq.push_back(i);
      while (num % i == 0)
        num /= i;
    }
  }
  if (num > 1)
    seq.push_back(num);
  std::sort(seq.begin(), seq.end());
  return seq;
}

void dfs(const std::vector<int> &seq, int &sum, const int &num, int pos,
         int mul, int len) {
  if (pos == seq.size()) {
    if (len) {
      if (len % 2 != 0)
        sum += num / mul;
      else
        sum -= num / mul;
    }
    return;
  }
  dfs(seq, sum, num, pos + 1, mul, len);
  dfs(seq, sum, num, pos + 1, mul * seq[pos], len + 1);
}

int que_prefix_nonmul_num(const std::vector<int> &seq, int l) {
  int sum = 0;
  int num = l;
  dfs(seq, sum, num, 0, 1, 0);
  // sum 表示有多少是seq中能凑出的倍数
  // l-sum 表示有多少是 k 的因子不能凑出的
  return l - sum;
}

int que(int l, int r, int k) {
  auto seq = prime(k);
  for(const auto& i: seq){
    std::cerr << i << " ";
  }
  std::cerr << std::endl;
  return que_prefix_nonmul_num(seq, r) - que_prefix_nonmul_num(seq, l - 1);
}

int main() {
  int k, l, r;
  std::cin >> k >> l >> r;

  std::cout << que(l,r,k);
  return 0;
}