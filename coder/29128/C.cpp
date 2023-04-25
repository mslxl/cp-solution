#include <bits/stdc++.h>
typedef long long ll;

#ifdef Lo
#define test if (1)
#else
#define test if (0)
#endif

#define rep(v, s, e) for (int v = s; v <= e; v++)

constexpr int maxn = 3 * 1e5 + 100;
constexpr int modd = 1e9 + 7;

ll w[maxn], prefix[maxn] = {0};

int n;

ll ask(int l, int r) {
  int flag = 1;
  if (l > r) {
    std::swap(l, r);
    flag = -1;
  }
  return (prefix[r] - prefix[l - flag]) * flag;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;

  rep(i, 1, n) std::cin >> prefix[i];
  rep(i, 1, n) std::cin >> w[i];
  rep(i, 2, n) { prefix[i] = (prefix[i - 1] + prefix[i]) % modd; }

  ll ans = 0;
  ll last = 0;
  rep(i, 1, n) {
    const auto wi = w[i];
    test std::cerr << "w=" << wi << ", ";

    const auto current = ask(i, n - (i - 1));
    test std::cerr << "current = " << current << std::endl;

    test std::cerr << "ans += " << (current + last) << " * " << wi << std::endl;
    if (current >= 0) {
      ans += (current + last) * wi;
      ans %= modd;
      last += current;
      last %= modd;
    } else {
      ans += ((current + last) % modd) * wi;
      ans %= modd;
      last = (last + current) % modd;
    }
  }
  std::cout << ans;

  return 0;
}
