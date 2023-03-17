#include<bits/stdc++.h>

int x,y;
int main(){
  std::cin >> x >> y;
  if(-1 <= x && x <= 1 && -1 <= y && y <= 1){
    std::cout << "yes";
  }else{
    std::cout << "no";
  }
  return 0;
}
