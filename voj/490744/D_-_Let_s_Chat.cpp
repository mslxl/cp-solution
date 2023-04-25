#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#undef Local
#endif
#ifdef Local
#define tout \
  if (1)     \
  std::cerr
#else
#define tout \
  if (0)     \
  std::cerr
#endif
using ll = long long;
using ull = unsigned long long;
#define rep(i, s, e) for (int i = s; i < e; i++)
#define fors(i, s, e) rep(i, s, e + 1)

template <typename T>
void read(T& value) {
  value = 0;
  char ch = getchar();
  bool flag = false;
  while (!std::isdigit(ch)) {
    if (ch == '-')
      flag = true;
    ch = getchar();
  }
  while (std::isdigit(ch)) {
    value = value * 10 + (ch - '0');
    ch = getchar();
  }
  if (flag)
    value *= -1;
}

template <typename T, typename... A>
inline void read(T& value, A&... _t) {
  read(value);
  read(_t...);
}

struct Span {
  int left, right;
  bool operator<(const Span& rhs) const { return this->left < rhs.left; }
  bool operator==(const Span& rhs) const {
    return this->left == rhs.left && this->right == rhs.right;
  }
};

void unique_span(std::vector<Span>& vec) {
  for (int i = 1; i < vec.size(); i++) {
    Span& pre = vec[i - 1];
    Span& cur = vec[i];
    if (pre.left < cur.left && pre.right > cur.right) {
      cur.right = pre.right;
      cur.left = pre.left;
    } else if (pre.left < cur.left && pre.right > cur.left) {
      cur.left = pre.left;
      pre.right = cur.right;
    }
  }

  vec.erase(std::unique(vec.begin(), vec.end()));
}

std::vector<Span> merge(const std::vector<Span> &lhs, const std::vector<Span>& rhs){


}

void solve() {
  ull days, consec, na, nb;
  read(days, consec, na, nb);
  std::vector<Span> A;
  std::vector<Span> B;
  rep(i, 0, na) {
    int l, r;
    read(l, r);
    A.push_back({l, r});
  }
  std::sort(A.begin(), A.end());

  rep(i, 0, nb) {
    int l, r;
    read(l, r);
    B.push_back({l, r});
  }

  unique_span(A);
  unique_span(B);
}

int main() {
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif

  int T;
  read(T);
  while (T--) {
    solve();
  }

  return 0;
}
