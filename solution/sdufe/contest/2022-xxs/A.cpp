#include<bits/stdc++.h>
int main(){
  int T;
  std::cin >> T;
  if(T == 1){
    int six = 0;
    for(int i = 1; i <= 100; i++){
      int num = i;
      while(num != 0){
        if(num%10 == 6){
          six++;
        }
        num /= 10;
      }
    }
    std::cout << six;
  }else if(T == 2){
    int v = (6 + 666) % 7;
    if(v == 0){
      std::cout << 7;
    }else{
      std::cout << v;
    }
  }else if(T == 3){
    std::cout << 6;
  }else if(T == 4) {
    // 2 3 5
    std::cout << 3;
  }else if(T == 5) {
    std::cout << 41;
  }else if(T == 6) {
    std::cout << "I love ACM!";
  }
  return 0;
}