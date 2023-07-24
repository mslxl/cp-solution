#include <algorithm>
#include<bits/stdc++.h>
#include <functional>

#define int long long 
int n;
using pii = std::pair<int, int>;

std::vector<pii> s;

const int modd = 365 * 24 * 60 * 60;

#undef int 
int main(){
  #define int long long 
  std::cin >> n;
  s.resize(n);
  for(int i = 0; i < n; i++) {
    std::cin >> s[i].first >> s[i].second;
  }

  std::sort(s.begin(), s.end(), [](pii a, pii b){
    return a.first * b.second < a.second * b.first;
  });

  int passed = 0;
  for(int i = 0; i < n; i++){
    passed += (s[i].second % modd * passed) % modd + s[i].first % modd;
    passed %= modd;
  }

  std::cout << passed % modd;
  return 0;
}