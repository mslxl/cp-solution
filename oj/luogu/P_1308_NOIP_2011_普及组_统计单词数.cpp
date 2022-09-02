#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <cstdio>
void to_lower(std::string &str) {
  for (auto &c : str) {
    c = std::tolower(c);
  }
}
namespace kmp {
const int maxlen = 1e6;
int next[maxlen];
void gen_next(const std::string &t) {
  int j =0, k = -1;
  next[0] = -1;
  while(j < t.size()){
      if(k == -1 || t[j] == t[k]){
          next[++j] = ++k;
      }else{
          k = next[k];
      }
  }
}

int count(const std::string &s, const std::string &t) {
  int fst_appear = -1;
  int i = 0, j = 0;
  int cnt = 0;
  gen_next(t);
  while (i < s.size()) {
    if (j == -1 || s[i] == t[j]) {
      i++, j++;
    } else {
      j = next[j];
    }
    if (j == t.size()) {
      // match successfully!
      // position is $i - t.size() + 1$
      cnt++;
      if (fst_appear == -1) {
        fst_appear = i - t.size();
      }
      j = next[j];
    }
  }


  if (fst_appear == -1) {
    std::cout << -1;
  } else {
    std::cout << cnt << " " << fst_appear;
  }

  return cnt;
}
} // namespace kmp
int main() {
  std::string t, s;
  std::getline(std::cin, t);
  std::getline(std::cin, s);
  to_lower(t);
  to_lower(s);
  kmp::count(s, t);
  return 0;
}