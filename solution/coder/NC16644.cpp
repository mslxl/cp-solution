#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
int p1, p2, p3;
void p(char c) {
  if (p1 == 3) {
    c = '*';
  }
  for (int i = 0; i < p2; i++) {
    std::cout << c;
  }
}

void ext(char s, char e) {
  if (e - s != 1) {
    if (e <= s || (std::isalpha(s) && std::isdigit(e)) ||
        (std::isdigit(s) && std::isalpha(e)) || s == '-' || e == '-') {
      std::cout << '-';
    } else {

      if (p1 == 2) {
        s = std::toupper(s);
        e = std::toupper(e);
      } else {
        s = std::tolower(s);
        e = std::tolower(e);
      }

      if (p3 == 2) {
        for (e--; e > s; e--) {
          p(e);
        }
      } else {
        for (s++; s < e; s++) {
          p(s);
        }
      }

    }
  }
}

int main() {
  std::string line;
  std::cin >> p1 >> p2 >> p3;
  std::cin >> line;
  std::cout << line[0];
  for (std::size_t idx = 1; idx < line.size(); idx++) {
    if (line[idx] == '-') {
      ext(line[idx - 1], line[idx + 1]);
    } else {
      std::cout << line[idx];
    }
  }

  return 0;
}