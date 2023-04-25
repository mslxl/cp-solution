#include<bits/stdc++.h>

int main(){
  int n;
  std::cin >> n;
  std::vector<int> seq(n);
  for(int i = 0; i < n; i++){
    std::cin >> seq[i];
  }

  int max = -10000 - 999;
  for(int i = 0; i < n; i++){
    int value = 0;
    for(int j = i; j < n; j++){
      value += seq[j];
      max = std::max(max, value);
    }
  }
  std::cout << max;


	return 0;
}