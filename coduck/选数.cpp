#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void solve();
int main() {
  solve();

  return 0;
}
#define int long long

const int maxn = 20 + 17;
int n, k;
int x[maxn];

bool is_prime(int k){
  if(k == 1) return false;
  for(int i = 2; i * i <= k; i++){
    if(k % i == 0) return false;
  }
  return true;
}


int dfs(int i, int sum, int k) {
  int ans = 0;
  for (int j = i + 1; j <= n; j++) {
    if (k - 1 == 0) {
      if (is_prime(sum + x[j])) {
        std::cerr << sum + x[j] << std::endl;
        ans++;
      }
    } else {
      ans += dfs(j, sum + x[j], k - 1);
    }
  }
  return ans;
}

void solve() {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++)
    std::cin >> x[i];
  // eular(*std::max_element(x + 1, x + n + 1) * 3);
  int ans = dfs(0, 0, k);
  std::cout << ans;
}