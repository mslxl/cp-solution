#include<bits/stdc++.h>

using ll = unsigned long long;
std::unordered_map<int, int> map;

ll calcS(ll a, ll b){
  return a * b + a + b;
}

int gen_table(){
  const int maxn = std::sqrt(1e7) /2;
  std::cerr << maxn << std::endl;
  for(int i = 0; i < maxn; i++){
    for(int j = 0; j < maxn; j++){
      auto v = calcS(i,j);
      if(v > 1e7) break;
      map[v]++;
    }
  }
  return 0;
}

int main(){
 std::ios::sync_with_stdio(false);
 std::cin.tie(nullptr);
 std::cout.tie(nullptr);
  gen_table();
  int T;
  std::cin >> T;
  while(T--){
    int k;
    std::cin >> k;
    std::cout << map[k] << "\n";
  }
  return 0;
}