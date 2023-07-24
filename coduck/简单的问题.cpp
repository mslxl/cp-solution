#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<stdlib.h>
#include<queue>
#include<climits>
#include<set>
#include<unordered_map>
#include<tuple>

using ll = long long;

int main(){
  int x;
  while(std::cin >> x && x != 0){
    if(x < 101){
      std::cout << "91\n";
    }else{
      std::cout << (x -10) << "\n";
    }
  }
  return 0;
}
