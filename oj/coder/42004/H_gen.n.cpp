#include<bits/stdc++.h>
#include <fstream>
#include <unordered_map>
using ll = unsigned long long;
std::map<int, int> map;

ll calcS(ll a, ll b){
  return a * b + a + b;
}

int main(){
  const int maxn = std::sqrt(1e7);
  const int maxr = 1e7;
  for(int i = 0; i < maxn; i++){
    for(int j = 0; j < maxn; j++){
      auto v =calcS(i, j);
      if(v > maxr) break;
      map[v]++;
    }
  }
  std::ofstream os("H_table.cpp");
  for(int i = 0; ){
      os << pr.second << ",";
  }
  os.flush();
  return 0;
}