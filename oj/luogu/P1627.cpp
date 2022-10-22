// 中位数
#include <bits/stdc++.h>

int main() {
  int n, b;
  std::cin >> n >> b;
  std::vector<int> seq(n);
  std::size_t pos_b = -1;
  for (int i = 0; i < n; i++) {
    int c;
    std::cin >> c;
    if (c > b) {
      seq[i] = 1;
    } else if (c < b) {
      seq[i] = -1;
    } else {
      seq[i] = 0;
      pos_b = i;
    }
  }
  std::vector<int> num(2*n+3);

  int result = 0;
  int sum = 0;

  for(int i = pos_b-1; i >=0 ;i--){
    sum += seq[i];
    num[n+sum]++;
    if(sum == 0) result++;
  }
  sum = 0;
  for(int i = pos_b+1; i < n; i++){
    sum += seq[i];
    result += num[n-sum];
    if(sum == 0) result++;
  }
  std::cout << result + 1;

  return 0;
}