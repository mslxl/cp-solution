#include <bits/stdc++.h>

void solve();

int main() {
  solve(); return 0;
}

const int maxn = 2e5 + 17;
#define int long long
int N, K;
int A[maxn];
int pre[maxn];
void solve() {
  std::cin >> N >> K;
  for (int i = 1; i <= N; i++){
    std::cin >> A[i];
    pre[i] = pre[i-1] + A[i];
  }

  int ans = 0;
  std::map<int, int> mp;
  for(int i = 1; i <= N; i++){
    ans += mp[pre[i] - K];
    mp[pre[i]]++;
  }
  std::cout << ans + mp[K];
}