#include <bits/stdc++.h>
#include <queue>
#include <utility>

int m, n, k;
const int maxm = 1e4 + 17;
const int maxn = 5e4 + 17;

int start, end;

struct edge {
  int to;
  int next;
  int w;
} e[maxn * 2 + 1];
int eid, head[maxm];

void add(int u, int v, int w) {
  eid++;
  e[eid].to = v;
  e[eid].next = head[u];
  e[eid].w = w;
  head[u] = eid;
}

void addbi(int u, int v, int w) {
  add(u, v, w);
  add(v, u, w);
}

std::vector<bool> dvis;

struct pr {
  int first;
  int second;
  std::vector<int> route;
  bool operator<(const pr &rhs) const { return first > rhs.first; }
};

pr dj() {
  dvis.resize(m);
  // using pr = std::pair<int,int>;
  std::priority_queue<pr, std::vector<pr>> seq;
  seq.push(pr{0, start, std::vector<int>()});

  while (!seq.empty()) {
    const auto data = seq.top();
    seq.pop();
    const int w = data.first, u = data.second;
    if (u == end) {
      return data;
    }

    if (dvis[u])
      continue;
    dvis[u] = true;

    for (int i = head[u]; i; i = e[i].next) {
      const int v = e[i].to;
      if (dvis[v])
        continue;
      const int nw = e[i].w + w;

      auto rr = data.route;
      rr.push_back(e[i].w);

      // seq.push(std::make_pair(nw, v));
      seq.push(pr{nw, v, rr});
    }
  }
  assert(false);
  return pr{
    0,0, std::vector<int>()
  };
}

int main() {
  std::cin >> m >> n >> k;
  std::cin >> start >> end;
  for (int i = 0; i < n; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    addbi(u, v, w);
  }


  pr d =  dj();
  std::sort(d.route.begin(), d.route.end(), std::greater<int>());
  int sum = 0;
  for(int i = k; i< d.route.size(); i++){
    sum += d.route[i];
  }
  std::cout << sum;
  return 0;
}