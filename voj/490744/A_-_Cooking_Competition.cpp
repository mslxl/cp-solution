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
const int feedbacks[][2]{{0, 0}, {1, 0}, {0, 1}, {1, 1}, {-1, -1}};
void solve() {
  int n;
  read(n);
  int kobayashi = 0, tohru = 0;
  while (n--) {
    int type;
    read(type);
    kobayashi += feedbacks[type][0];
    tohru += feedbacks[type][1];
  }

  if (kobayashi == tohru) {
    std::cout << "Draw" << std::endl;
  } else {
    std::cout << (kobayashi > tohru ? "Kobayashi" : "Tohru") << std::endl;
  }
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
