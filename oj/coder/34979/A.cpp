#include <iostream>
#include <sstream>
int main() {
#define int long long
  std::string line;
  std::getline(std::cin, line);
  std::stringstream ss;
  ss << line;
  int num;
  bool has17 = false, has18 = false;
  while (ss >> num) {
    if (num == 17)
      has17 = true;
    else if (num == 18)
      has18 = true;
    if (has17 && has18) {
      break;
    }
  }
  if (has17 && has18) {
    std::cout << "both";
  } else if (has17) {
    std::cout << 17;
  } else if (has18) {
    std::cout << 18;
  } else {
    std::cout << "none";
  }

  return 0;
}