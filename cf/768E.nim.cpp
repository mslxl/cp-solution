#include<bits/stdc++.h>

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  int sg = 0;
  for(int i = 0; i < n; i++){
    int x;
    std::cin >> x;
    for(int j = 1; ; j++){
      x -= j;
      if(x - (j+1) < 0){
        sg ^= j;
        break;
      }
    }
  }
  if(sg == 0){
    std::cout << "YES";
  }else{
    std::cout << "NO";
  }
}