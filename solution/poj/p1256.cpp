// Problem: Anagram
// Contest: POJ - Southwestern European Regional Contest 1995
// URL: http://poj.org/problem?id=1256
// Memory Limit: 10 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// clang-format off
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
void solve(const std::size_t testcase);

int main() {
  std::size_t t = 1;
  std::cin >> t;
  for(int i = 1; i <= t; i++) solve(t);
  return 0;
}

// clang-format on

struct Cmp{
  bool operator()(const char a, const char b){
    if (a + 32 == b || a - 32 == b) return a < b;
    return tolower(a) < tolower(b);
  }
};


void solve(const std::size_t testcase){
  std::string line;
  std::cin >> line;
  std::sort(line.begin(), line.end(), Cmp());
  do{
    std::cout << line << "\n";
  }while(std::next_permutation(line.begin(), line.end(), Cmp()));
}