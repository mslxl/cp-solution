#include <bits/stdc++.h>
typedef long long ll;

std::priority_queue<ll, std::vector<ll>, std::less<ll>> bigger;
std::priority_queue<ll, std::vector<ll>, std::greater<ll>> smaller;
ll n;

int main() {
  std::ios::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cin.tie(nullptr);

  std::cin >> n;
  ll input;
  std::cin >> input;
  std::cout << input << std::endl;
  bigger.push(input);
  for (int i = 1; i < n; i++) {
    std::cin >> input;
    if (input <= bigger.top()) {
      bigger.push(input);
    } else {
      smaller.push(input);
    }
    while (smaller.size() > bigger.size()) {
      bigger.push(smaller.top()), smaller.pop();
    }

    while (smaller.size() + 1 < bigger.size()) {
      smaller.push(bigger.top()), bigger.pop();
    }
    if (i % 2 == 0) {
      std::cout << bigger.top() << std::endl;
    }
  }

  return 0;
}
