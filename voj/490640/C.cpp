#include <bits/stdc++.h>

#ifdef Local
#define tout \
  if (1)     \
  std::cerr
#else
#define tout \
  if (0)     \
  std::cerr
#endif

#define rep(i, s, e) for (int i = (s); (i) < e; i++)

typedef long long ll;
const ll inf = 0x3f3f3f3f3f;

struct Point {
  int x, y, z;
  Point() {}
  Point(int x, int y, int z) : x(x), y(y), z(z) {}
  bool operator<(const Point b) const {
    if (x != b.x)
      return x < b.x;
    if (y != b.y)
      return y < b.y;
    if (z != b.z)
      return z < b.z;
    return 0;
  }

  ll dis(Point b) const {
    const auto& a = *this;
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
           (a.z - b.z) * (a.z - b.z);
  }
};

Point pts[8];

bool is_cube() {
  ll max_dis = -1;
  rep(i, 0, 8)
      rep(j, 0, i) if (!(pts[i] < pts[j]) && !(pts[j] < pts[i])) return false;

  std::vector<ll> all_dis;
  rep(i, 0, 8) rep(j, 0, i) all_dis.push_back(pts[i].dis(pts[j]));
  std::sort(all_dis.begin(), all_dis.end());
  rep(i, 0, 12) rep(j, 0, i) if (all_dis[i] != all_dis[j]) return false;
  rep(i, 0, 12) rep(j, 0, i) if (all_dis[12 + i] != all_dis[12 + j]) return false;
  rep(i, 0, 4) rep(j, 0, i) if (all_dis[24 + i] != all_dis[24 + j]) return false;
  if (all_dis[0] + all_dis[12] != all_dis[24])
    return 0;
  return true;
}
void solve() {
  for (int i = 0; i < 8; ++i) {
    std::cin >> pts[i].x >> pts[i].y >> pts[i].z;
  }
  std::cout << (is_cube() ? "YES\n" : "NO\n");
}

int main() {
  int n;
  std::cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
