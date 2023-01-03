#include<bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main(){
  for(int i = 10; ; i++){
    ll sum = 0;
    ll num = i;
    ll bit = 1;
    while(num != 0){
      sum += (num % 10) * bit;
      bit *= 16;
      num/=10;
    }
    if(sum % i == 0){
      std::cout << i;
      return 0;
    }
  }

	return 0;
}