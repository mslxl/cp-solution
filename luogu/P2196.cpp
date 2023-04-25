#include<bits/stdc++.h>
#ifdef Lo
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;

const int maxn = 20 + 5;
int N;

struct Basement{
  int number;
  bool sec[maxn];
} bs[maxn];

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;
  for(int i = 0; i < N; i++){
    std::cin >> bs[i].number;
  }
  for(int idx = 3; idx <= N-1;idx++){
    const int i = idx - 3;
    for(int j = 0; j < N-1; j++){
      int sec;
      std::cin >> sec;
      if(sec == )
      bs[i].sec[j] = true;

    }
  }

  return 0;
}
