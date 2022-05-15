#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#undef Local
#endif

using ll = long long;
using ull = unsigned long long;

inline ull manhattan(const std::pair<ll, ll>& loc) {
  return std::abs(loc.first) + std::abs(loc.second);
}

void solve() {
  ll n, k;
  std::string instruction;
  std::cin >> n >> k >> instruction;

  std::pair<ll, ll> loc = std::make_pair(0, 0);
  ull max = 0;

  if (k == 0) {
    std::cout << 0 << std::endl;
    return;
  }

  if (k <= 1) {
    for (const auto& c : instruction) {
      if (c == 'U') {
        loc.second++;
      } else if (c == 'D') {
        loc.second--;
      } else if (c == 'L') {
        loc.first--;
      } else if (c == 'R') {
        loc.first++;
      }

      max = std::max(max, manhattan(loc));
    }
  } else if (k == 2) {
    for (const auto& c : instruction) {
      if (c == 'U') {
        loc.second++;
      } else if (c == 'D') {
        loc.second--;
      } else if (c == 'L') {
        loc.first--;
      } else if (c == 'R') {
        loc.first++;
      }

      max = std::max(max, manhattan(loc));
    }
    for (const auto& c : instruction) {
      if (c == 'U') {
        loc.second++;
      } else if (c == 'D') {
        loc.second--;
      } else if (c == 'L') {
        loc.first--;
      } else if (c == 'R') {
        loc.first++;
      }

      max = std::max(max, manhattan(loc));
    }
  } else if (k >= 3) {
    for (const auto& c : instruction) {
      if (c == 'U') {
        loc.second++;
      } else if (c == 'D') {
        loc.second--;
      } else if (c == 'L') {
        loc.first--;
      } else if (c == 'R') {
        loc.first++;
      }

      max = std::max(max, manhattan(loc));
    }
    loc.first *= (k - 1);
    loc.second *= (k - 1);
    for (const auto& c : instruction) {
      if (c == 'U') {
        loc.second++;
      } else if (c == 'D') {
        loc.second--;
      } else if (c == 'L') {
        loc.first--;
      } else if (c == 'R') {
        loc.first++;
      }

      max = std::max(max, manhattan(loc));
    }
  }

  std::cout << max << std::endl;
}

int main() {
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
