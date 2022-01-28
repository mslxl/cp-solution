#include <algorithm>
#include <iostream>
#include <string>
int main() {
  int x;
  std::cin >> x;
  std::string str;
  std::cin >> str;
  std::next_permutation(str.begin(), str.end());
  std::cout << str;
}
