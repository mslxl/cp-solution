// clang-format off
#include <bits/stdc++.h> 
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int maxn = 1e6 + 17;

// ll A[maxn], pre[maxn];
std::vector<ll> A;
std::vector<ll> pre;
int main() {
  int n, q;
  std::cin >> n >> q;
  
  A.resize(maxn);
  pre.resize(maxn);
  
  for(int i = 1; i <= n; i++) std::cin >> A[i];
  for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + A[i];
  
  while(q--){
    int l, r;
    std::cin >> l >> r;
    std::cout << pre[r] - pre[l-1] << "\n";
  }
  
  return 0;
}
