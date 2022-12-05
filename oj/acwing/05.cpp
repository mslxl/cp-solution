#include<bits/stdc++.h>
struct Item{
  int w,v;
};
const int maxn = 2000 + 17;

int F[maxn];

int main(){
  int N,V;
  std::cin >> N >> V;
  std::vector<Item> items;
  for(int i = 0; i < N; i++){
    int v,w,s;
    std::cin >> v >> w >> s;
    for(int k = 1; k <= s; k *= 2){
      s -= k;
      items.push_back({w*k, v*k});
    }
    if(s > 0) items.push_back({w * s,v * s});
  }

  for(const auto& i: items){
    for(int j = V; j >= i.v; j--){
      F[j] = std::max(F[j], F[j-i.v]+i.w);
    }
  }
  std::cout << F[V];

  return 0;
}