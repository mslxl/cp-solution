#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;

int main(){
  int n;
  double price, input;
  std::cin >> n >> price;

  while(n--){
    std::cin >> input;
    if(input < price){
      printf("On Sale! %.1lf", input);
      if(n != 0) printf("\n");
    }
  }
  return 0;
}
