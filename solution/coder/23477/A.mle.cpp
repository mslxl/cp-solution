#include <iostream>
// MLE
typedef unsigned long long ll;
ll n, m;
bool solve(ll hp, ll mp, ll atk, ll cn, ll cm) {
  if (hp == 0) {
    return true;
  } else if (hp < 0) {
    return false;
  } else if (hp > 0 && ((mp == 0 && cm == 0) || (cn == 0))) {
    return false;
  }
  bool fst = false, snd = false;
  if (mp > 0 && cn > 0) {
    fst = solve(hp - atk, mp - 1, atk + 1, cn - 1, cm);
  }
  if (cm > 0) {
    snd = solve(hp, mp + 1, atk + 1, cn, cm - 1);
  }
  return fst || snd;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> m;
  ll k;
  ll hp;
  std::cin >> k;
  while (k--) {
    std::cin >> hp;
    if (solve(hp, 1, 1, n, m)) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
}
