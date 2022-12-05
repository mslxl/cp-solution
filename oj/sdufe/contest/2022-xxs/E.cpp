#include <bits/stdc++.h>
using ll = long long;

int main() {
  std::map<ll, ll> s;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    ll v;
    std::cin >> v;
    s[v]++;
  }
  if (s.count(0)) {
    if (s[0] >= 2) {
      std::cout << 0;
    } else if(s[0] == 1) {
      std::cout << 1;
    }
  } else {
    if(s.count(1)){
      std::cout << s.size() - 1;
    }else{
      std::cout << s.size();
    }
  }
  return 0;
}