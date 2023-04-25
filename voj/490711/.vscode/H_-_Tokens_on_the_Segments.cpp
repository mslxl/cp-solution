#include <bits/stdc++.h>
struct Seg {
  int l, r;
  bool operator<(Seg a) const {
    if (l == a.l)
      return r > a.r;
    return l > a.l;
  }
} pos;

void solve() {
  std::priority_queue<Seg> que;
  int n;
  std::cin >> n;
  std::vector<Seg> seq(n);
  for (int i = 0; i < n; i++) {
    std::cin >> seq[i].l >> seq[i].r;
    que.push(seq[i]);
  }
  int num = 0;
  int maxx = 0;

  while (!que.empty()) {
    pos = que.top();
    que.pop();
    if (pos.l > maxx) {
      maxx = pos.l;
      num++;
    } else if (pos.l < pos.r) {
      pos.l++;
      que.push(pos);
    }
  }
  std::cout << num << std::endl;
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}