#include <bits/stdc++.h>

template<typename A, typename BaseT>
typename std::enable_if<std::is_integral<BaseT>::value, A>::type
qpow(A a, BaseT n, BaseT modd){
    decltype(a) ans = 1;
    while (n){
        if (n & 1) ans = (ans * a) % modd;
        n >>= 1;
        a = (a * a) % modd;
    }
    return ans % modd;
}

using ll = long long;
int map[][9] = {
{0,0,0,0,0,0,0,0,0,},
{0,15,339,4761,52929,517761,4767849,43046721,387420489},
{0,339,16485,518265,14321907,387406809,460338013,429534507,597431612},
{0,4761,518265,43022385,486780060,429534507,792294829,175880701,246336683},
{0,52929,14321907,486780060,288599194,130653412,748778899,953271190,644897553},
{0,517761,387406809,429534507,130653412,246336683,579440654,412233812,518446848},
{0,4767849,460338013,792294829,748778899,579440654,236701429,666021604,589237756},
{0,43046721,429534507,175880701,953271190,412233812,666021604,767713261,966670169},
{0,387420489,597431612,246336683,644897553,518446848,589237756,966670169,968803245}
};
#define int ll


const int modd = 1e9 + 7;
void solve() {
  int n, m;
  std::cin >> n >> m;
  if (n > m)
    std::swap(n, m);
  if(n == 1) {
    std::cout << 0 << "\n";
    return;
  }
  if(m > 9){
    int result = qpow(3LL, n * m, modd);
    std::cout << result << "\n"; 
  }else{
    std::cout << map[n-1][m-1]%modd << "\n";
  }
}

#undef int
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}
