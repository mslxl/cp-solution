#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

typedef long long ll;

const ll modd = 80112002;

struct Edge {
  ll from, to;
};

const ll maxn = 5010;
ll n, m;

ll indegree[maxn];
std::array<std::vector<Edge>, maxn> facial;
ll num_link[maxn];

ll ans = 0;

int main() {
  std::memset(indegree, 0, sizeof(indegree));
  std::memset(num_link, 0, sizeof(num_link));

  scanf("%lld%lld", &n, &m);
  for (ll i = 0; i < m; i++) {
    ll u, v;
    scanf("%lld%lld", &u, &v);
    facial[u].push_back(Edge{u, v});
    // prllf("%lld was eaten by %lld\n",u,v);
    indegree[v]++;
  }

  std::queue<ll> zero_degree;
  for (ll i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      zero_degree.push(i);
      num_link[i] = 1;
    }
  }

  while (!zero_degree.empty()) {
    ll current_eaten = zero_degree.front();
    // printf("remove %lld \n", current_eaten);
    zero_degree.pop();

    if (facial[current_eaten].empty()) {
      ans += num_link[current_eaten];
      ans %= modd;
      continue;
    }
    for (auto &v : facial[current_eaten]) {
      num_link[v.to] += num_link[current_eaten];
      num_link[v.to] %= modd;
      // printf("node %lld have %lld links\n", v.to, num_link[v.to]);

      indegree[v.to]--;
      if (indegree[v.to] == 0) {
        zero_degree.push(v.to);
      }
    }
  }
  printf("%lld", ans);

  return 0;
}
