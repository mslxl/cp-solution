#include<bits/stdc++.h>

const int maxn = 1e5 + 17;
using ll = long long;
ll c[maxn];

int main(){
  #define int ll
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++){
    std::cin >> c[i];
  }

  int m, p1, s1, s2;
  std::cin >> m >> p1 >> s1 >> s2;
  int left = 0;
  int right = 0;
  c[p1]+=s1;
  for(int i = 1; i < m; i++){
    left += c[i] * (m - i);
  }

  for(int i = m; i <= n; i++){
    right += c[i] * (i - m);
  }

  int best = std::abs(right - left), idx = m;

  for(int i = 1; i <= n; i++){
    int diff = std::abs(right + (i-m) * s2 - left);
    if(diff <= best){
      if(diff == best){
        idx = std::min(idx, i);
      }else{
        idx = i;
      }
      best = diff;
    }
  }
  std::cout << idx;


  return 0;
}