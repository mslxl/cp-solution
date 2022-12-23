#include<bits/stdc++.h>

int main(){
  int n;
  std::cin >> n;
  std::vector<int> seq(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> seq[i];
  }
  std::vector<int> prefix(n+1);
  for(int i = 1; i <=n; i++){
    prefix[i] = prefix[i-1] + seq[i];
  }

  int max = -10000 - 999;
  for(int i = 1; i <= n; i++){
    for(int j = i; j <= n; j++){
      max = std::max(max, prefix[j] - prefix[i-1]);
    }
  }
  std::cout << max;


	return 0;
}