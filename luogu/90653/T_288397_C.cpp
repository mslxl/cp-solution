#include <bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
#ifdef ONLINE_JUDGE
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  std::string line;
  
  std::vector<std::string> lines;
  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }
  ll s =std::ceil(std::log10(ld(lines.size())));


  std::string format = "%";
  format += std::to_string(s);
  format += "lld %s\n";

  for(ll i = 1; i <= lines.size(); i++){
    printf(format.data(), i, lines[i-1].data());
  }


  return 0;
}