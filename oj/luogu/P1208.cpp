#include <algorithm>
#include <iostream>
#include <vector>

struct Milk {
  int p, a;
  bool operator<(const Milk &rhs) const { return this->p < rhs.p; }
};

std::istream &operator>>(std::istream &is, Milk &rhs) {
  is >> rhs.p >> rhs.a;
  return is;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Milk> p(m);
  for (int i = 0; i < m; i++) {
    std::cin >> p[i];
  }
  std::sort(p.begin(), p.end());
  int cost = 0;
  for (auto iter = p.begin(); n > 0; iter++) {
    if (iter->a > n) {
      cost += iter->p * n;
      break;
    } else {
      cost += iter->p * iter->a;
      n -= iter->a;
    }
  }
  std::cout << cost;
  return 0;
}
