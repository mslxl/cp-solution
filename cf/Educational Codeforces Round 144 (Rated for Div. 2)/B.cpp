// 自分の得意な言語で
// Let's チャレンジ！！

// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); }
void solve(const std::size_t testcase);
#define rep(NAME, MAX) for(decltype(MAX) NAME = 0; NAME < MAX; NAME++)
#define rep1(NAME, MAX) for(decltype(MAX) NAME = 1; NAME <= MAX; NAME++)
#define repv0(NAME, START) for(decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for(decltype(START) NAME = START; NAME >= 1; NAME--)
int main() {
  std::size_t t = 1;
  read(t);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  rep1(i, t) solve(t);
  return 0;
}
// clang-format on

void solve(const std::size_t testcase) {
  std::string a, b;
  std::cin >> a >> b;
  if(a == b){
    std::cout << "YES\n" << a;
    return;
  }

  int i = 0, j = 0;
  std::string t = "";
  while (i < a.size() && j < b.size()) {
    if (a[i] != b[j]) {
      t += "*";
      int ni = i, nj = j;
      for(; ni < a.size(); ni++){
        for(; nj < b.size(); nj++){

        }
      }

    } else {
      t += a[i];
      i++;
      j++;
    }
  }

  int asterisk = 0, alphabet = 0;
  for (const auto &ch : t) {
    if (ch == '*') {
      asterisk++;
    } else {
      alphabet++;
    }
  }
  if (asterisk > alphabet) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n" << t;
  }
}
