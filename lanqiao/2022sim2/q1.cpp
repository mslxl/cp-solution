#include<bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main(){
  const int min = 2022;
  for(int i = min; ;i++){
    int n = 0;
    for(int j = 0; j < 6; j++){
      if(((i >> j) & 1) == 0){
        n++;
      }
    }
    if(n == 6){
      std::cout << i;
      return 0;
    }
  }

	return 0;
}