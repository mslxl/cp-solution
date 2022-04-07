#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a1, a2, n;
  std::queue<int> seq;
  std::cin >> a1 >> a2 >> n;
  seq.push(a1);
  seq.push(a2);

  while(n > 0){
    int x,y;
    x = seq.front(), seq.pop();
    n--;
    std::cout << x;
    if(n > 0) std::cout << ' ';
    y = seq.front();
    int tmp = x * y;
    if(tmp > 9){
      seq.push(tmp / 10);
      seq.push(tmp % 10);
    }else{
      seq.push(tmp);
    }
  }
  

  return 0;
}
