#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;

const int maxq = 1e6 + 17;
int seq[maxq];
int max = 0, min = maxq;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int N;
  std::cin >> N;
  int x;
  for (int i = 0; i < N; i++) {
    std::cin >> x;
    seq[x]++;
    max = std::max(max, x);
    min = std::min(min, x);
  }
  std::cout << min << ' ' << seq[min] << std::endl 
      << max << ' '<< seq[max];

  return 0;
}
