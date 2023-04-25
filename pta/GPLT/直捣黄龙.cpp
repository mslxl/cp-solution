#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 210, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;

struct node {
  int to, data;
};
unordered_map<string, int> Hash;
unordered_map<int, string> rHash;
vector<node> v[MAX_N];
int n, m;
string s, d;
/* foe: 每个点的敌人数，dis: 路径长度，num: 路径的节点数，w:
 * 路径消灭的敌人总数，book: 最短路径条数，pre：前驱*/
int foe[MAX_N], dis[MAX_N], num[MAX_N], w[MAX_N], book[MAX_N], pre[MAX_N];

void dfs(int x) {
  if (x == pre[x]) {
    cout << rHash[x];
    return;
  }
  dfs(pre[x]);
  cout << "->" << rHash[x];
}

void Dijkstra(int s) {
  iota(pre, pre + n + 1, 0);
  memset(dis, INF, sizeof dis);
  dis[s] = 0, num[s] = 1, w[s] = foe[s], book[s] = 1;

  priority_queue<PII, vector<PII>, greater<PII>> que;
  que.push({dis[s], s});

  while (que.size()) {
    auto t = que.top();
    que.pop();
    int u = t.second, e = t.first;

    if (e > dis[u]) continue;

    for (auto c : v[u]) {
      if (dis[u] + c.data < dis[c.to]) {
        dis[c.to] = dis[u] + c.data;
        num[c.to] = num[u] + 1;
        w[c.to] = w[u] + foe[c.to];
        book[c.to] = book[u];
        pre[c.to] = u;
        que.push({dis[c.to], c.to});
      } else if (dis[u] + c.data == dis[c.to]) {
        book[c.to] += book[u];
        if (num[u] + 1 > num[c.to]) {
          num[c.to] = num[u] + 1;
          w[c.to] = w[u] + foe[c.to];
          pre[c.to] = u;
        } else if (num[u] + 1 == num[c.to] && w[u] + foe[c.to] > w[c.to]) {
          w[c.to] = w[u] + foe[c.to];
          pre[c.to] = u;
        }
      }
    }
  }
}

int main() {
  cin >> n >> m >> s >> d;
  for (int i = 1; i < n; i++) {
    string s;
    cin >> s >> foe[i];
    Hash[s] = i;
    rHash[i] = s;
  }
  Hash[s] = 0, rHash[0] = s;
  while (m--) {
    string a, b;
    int data;
    cin >> a >> b >> data;
    v[Hash[a]].push_back({Hash[b], data});
    v[Hash[b]].push_back({Hash[a], data});
  }
  Dijkstra(Hash[s]);
  dfs(Hash[d]);
  cout << "\n" << book[Hash[d]] << ' ' << dis[Hash[d]] << ' ' << w[Hash[d]];

  return 0;
}
