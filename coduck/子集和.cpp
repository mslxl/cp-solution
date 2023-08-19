#include<bits/stdc++.h>
#include <bitset>

const int maxn = 20 + 17;
const int maxt = 1e8 + 17;
int n, t;
int a[maxn];
std::bitset<maxt> f;

int main(){
  std::cin >> n >> t;

  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }
  f[0] = true;
  for(int i = 1; i <= n; i++){
    for(int j = t; j >= a[i]; j--){
      f[j] = f[j] || f[j - a[i]];
    }
  }
  if(f[t]){
    std::cout << "Yes";
  }else{
    std::cout << "No";
  }

  return 0;
}