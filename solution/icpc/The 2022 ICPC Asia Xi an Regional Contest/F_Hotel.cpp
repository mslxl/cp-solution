#include <bits/stdc++.h>

#define rep(NAME, MAX) for (int NAME = 0; NAME < MAX; i++)
#define rep1(NAME, MAX) for (int NAME = 1; NAME <= MAX; i++)
#define repv0(NAME, START) for (int NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for (int NAME = START; NAME >= 1; NAME--)

using ll = long long;
using ul = unsigned long long;
using ld = long double;


int main() {
#ifdef ONLINE_JUDGE
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  int numOfTeam, cost1, cost2;
  std::cin >> numOfTeam >> cost1 >> cost2;
  ll totalCost = 0;
  std::string team;
  std::getline(std::cin, team);
  rep(i, numOfTeam) {
    std::getline(std::cin, team);
    std::set<char> set(team.begin(), team.end());
    if (set.size() == 3) {
      totalCost += std::min(3 * cost1, 3 * cost2);
    } else if (set.size() == 2) {
      totalCost += std::min(
          3 * cost1, std::min(cost1 + cost2, std::min(2 * cost1 + cost2, 2 *cost2)));
    } else if (set.size() == 1) {
      totalCost += std::min(3 * cost1, std::min(2 * cost2, cost1 + cost2));
    }
  }
  std::cout << totalCost << "\n";

  return 0;
}