#include<bits/stdc++.h>
#include <set>


std::map<int, int> factor;
int cnt = 0;

void disolve(int n){
  for(int i = 2;i * i <= n; i++){
    while(n % i == 0){
      factor[i]++;
      cnt++;
      n /= i;
    }
  }
  if(n != 0){
    cnt++;
    factor[n]++;
  }
}

int main(){
  int n;
  std::cin >> n;
  disolve(n);
  std::cout << cnt << "\n";
  for(auto it: factor){
    for(int i = 0; i < it.second; i++){
      std::cout << it.first << " ";
    }
  }

  return 0;
}