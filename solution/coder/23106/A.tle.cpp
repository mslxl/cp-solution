#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
typedef unsigned long long ll;
ll modd = 998244353;
ll n;
ll *a;
ll door[10] = {0};
std::map<ll, ll> mem;

ll num_root(ll num) { return (num - 1) % 9 + 1; }
void dfs(ll cur_pos, ll cur_sum) {
  cur_sum += a[cur_pos];
  door[num_root(cur_sum)]++;
  for (int i = cur_pos + 1; i <= n; i++) {
    dfs(i, cur_sum);
  }
}

int main() {
  scanf("%lld", &n);
  a = new ll[n + 10];
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
  }
  for (int i = 1; i <= n; i++) {
    dfs(i, 0);
  }
  for (int i = 1; i <= 9; i++) {
    printf("%lld ", door[i] % modd);
  }
  return 0;
}
