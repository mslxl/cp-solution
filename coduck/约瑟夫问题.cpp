#include<bits/stdc++.h>
#include <queue>


int main(){
  std::queue<int> seq;
  int n, m;
  std::cin >> n >> m;
  for(int i = 1; i <= n; i++){
    seq.push(i);
  }
  int idx = 0;
  while(!seq.empty()){
    auto v = seq.front();
    seq.pop();
    idx++;
    if(idx == m){
      std::cout << v << " ";
    }else{
      seq.push(v);
    }
    idx %= m;
  }
  return 0;
}