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
  ll n;
  read(n);
  std::vector<ll> a(n), f1(n + 1), f2(n + 1);
  ll ans_flag = 0;
  rep(i, n) {
    read(a[i]);
    f1[i + 1] = f2[i + 1] = -1;
  }
  std::vector<ll> seq1(n), seq2(n);

  rep(i, n) { seq2[i] = seq1[i] = 0; }
  std::set<ll> occupy1, occupy2;
  rep(i, n) {
    if (f1[a[i]] == -1) {
      f1[a[i]] = i;
      seq1[i] = a[i];
    } else if (f2[a[i]] == -1) {
      f2[a[i]] = i;
      seq2[i] = a[i];
    } else {
      ans_flag = 1;
    }
  }
  if (ans_flag == 1) {
    std::cout << "NO\n";
    return;
  }
  rep(i, n) {
    if (f1[i + 1] == -1)
      occupy1.insert(i + 1);
    if (f2[i + 1] == -1)
      occupy2.insert(i + 1);
  }
  rep(i, n) {
    if (seq1[i] == 0) {
      auto iter = occupy1.upper_bound(seq2[i]);
      if (iter == occupy1.begin()) {
        ans_flag = 1;
        break;
      } else {
        iter--;
        seq1[i] = *iter;
        occupy1.erase(iter);
      }
    } else {
      auto it = occupy2.upper_bound(seq1[i]);
      if (it == occupy2.begin()) {
        ans_flag = 1;
        break;
      } else {
        it--;
        seq2[i] = *it;
        occupy2.erase(it);
      }
    }
  }
  if (ans_flag == 1) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  rep(i, n) { std::cout << seq1[i] << " "; }
  std::cout << "\n";
  rep(i, n) { std::cout << seq2[i] << " "; }
  std::cout << "\n";
}
