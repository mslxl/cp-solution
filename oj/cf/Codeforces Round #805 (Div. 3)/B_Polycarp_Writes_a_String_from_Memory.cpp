#include <iostream>
#include <string>
#include <cstring>

using ll = long long;
void solve() {
  std::string line;
  std::cin >> line;
  ll pos = 0;
  bool dict[26];
  ll days;
  for (days = 0; pos < line.size(); days++) {
    int mem_alpha = 0;
    std::memset(dict, false, sizeof(dict));
    while(mem_alpha < 3 || dict[line[pos]-'a']){
        int ch = line[pos] - 'a';
        if(!dict[ch]){
            dict[ch] = true;
            mem_alpha++;
        }
        pos++;
    }
  }
  std::cout << days << std::endl;
}
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}