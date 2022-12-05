#include<bits/stdc++.h>
#include <limits>
using ll =  unsigned long long;
int main(){
  ll n;
  std::cin >> n;

  std::vector<ll> seq(n);
  for(int i = 0; i < n; i++){
    std::cin >> seq[i];
  }

  ll last = seq[0];
  ll group_num = 0;
  ll max = std::numeric_limits<ll>::min();
  for(int i = 1; i < n; i++){
    if(seq[i] < last){
      max = std::max(seq[i], std::max(last, max));
    }else if(seq[i] >= last){
      if(seq[i] > max){
        group_num++;
      }
      
    }
    last = seq[i];
  }

  std::cout << group_num + 1;

  return 0;
}