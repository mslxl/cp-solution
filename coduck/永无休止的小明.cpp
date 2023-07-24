#include<bits/stdc++.h>

int main(){
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++){
    if(i % 2== 0){
      std::cout << "我猜";
    }else{
      std::cout << "你猜";
    }
  }
  if(n != 1){
    std::cout << "不猜";
  }
  return 0;
}