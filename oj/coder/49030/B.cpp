#include <bits/stdc++.h>
using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  ll n, m;
  std::cin >> n >> m;
  std::vector<ll> seq(n);
  for(int i = 0; i < n; i++) std::cin >> seq[i];
  ll atk = 2;
  ll damage = 0;
  for(int i = 0; i < m; i++){
    for(auto& hp: seq){
      hp-=atk;
      if(hp==0){
        atk++;
      }
    }
    damage += atk;
  }
  std::cout << damage;

  return 0;
}
