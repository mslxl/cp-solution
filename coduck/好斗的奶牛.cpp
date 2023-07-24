
#include<iostream>
#include<algorithm>
#define ll long long
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
ll a[maxn];
ll n, c;

bool check(ll m) {
  ll cnt = a[0], num = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] - cnt >= m) {
      cnt = a[i];
      num++;
    }
  }
  return num >= c;
}

void solve(std::size_t testcase) {
  while (std::cin >> n >> c) {
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::sort(a, a + n);

    ll l = 0, r = a[n - 1], mid;
    ll ans = 0;
    while (l <= r) {
      mid = l + (r - l) / 2;
      if (check(mid)){
        ans = mid;
        l = mid+1;
      }
      else{
        r = mid-1;
      }
        
    }
    std::cout << ans << "\n";
  }
}
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  solve(0);
  return 0;
}