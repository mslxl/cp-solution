#include <bits/stdc++.h>

#ifdef Lo
#define test if (1)
#else
#define test if (0)
#endif

struct Impl {
  bool operator()(const std::string &rhs, const std::string &lhs) {
    return (rhs + lhs) < (lhs + rhs);
  }
};

std::priority_queue<std::string, std::vector<std::string>, Impl> seq;
int n;
bool is_zero = true;

int main() {
  std::string s;
  std::cin >> n;

  while (n--) {
    std::cin >> s;
    is_zero = is_zero && (s == "0");
    test std::cout << "input " << s << std::endl;
    seq.push(s);
  }

  if (is_zero) {
    std::cout << 0;
  } else {
    while (!seq.empty()) {
      std::cout << seq.top();
      seq.pop();
    }
  }
  return 0;
}
