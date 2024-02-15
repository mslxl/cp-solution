#include<bits/stdc++.h>
using pii = std::pair<int,int>;
template<typename T> using V = std::vector<T>;

V<int> mem;
void init(){
  mem.resize(70);
  mem[0] = 0;
  int limits = 2, cnt = 0, num = 1;
  for(int i = 1; i < 70; i++){
    mem[i] = num;
    cnt++;
    if(cnt == limits){
      num++;
      limits++;
      cnt  = 0;
    }
  }
}

int main(){
  init();
  std::cin.tie(0)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  int sg = 0;
  for(int i = 0; i < n; i++){
    int v;
    std::cin >> v;
    sg ^= mem[v];
  }
  if(sg == 0){
    std::cout << "YES";
  }else{
    std::cout << "NO";
  }

  return 0;
}