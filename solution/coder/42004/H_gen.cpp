#include<bits/stdc++.h>
#include <fstream>
#include <unordered_map>
using ll = unsigned long long;
std::map<int, int> map;

ll calcS(ll a, ll b){
  return a * b + a + b;
}

int main(){
  const int maxn = 1e7 -2;
  const int maxr = 1e7;
  std::cout << maxn << std::endl;
  int cnt = 0;
  for(int i = 0; i < maxn; i++){
    ll max = 0;
    for(int j = i+1; j < maxn; j++){
      auto v =calcS(i, j);
      if(v > maxr) break;
      max = std::max(v, max);
      map[v]++;
    }
    std::cout << i << "/" << maxn << " " << max << std::endl;
    if(max == 0){
      cnt++;
    }else{
      cnt=0;
    }
    if(cnt > 3){
      break;
    }
  }
  std::ofstream os("H_table.cpp");
  for(auto pr: map){
      os << pr.second << ",";
  }
  os.flush();
  return 0;
}