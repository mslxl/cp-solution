// Problem: D. Two-Colored Dominoes
// Contest: Codeforces - Pinely Round 2 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1863/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
// clang-format off
#include <bits/stdc++.h> 
using i16 = short; using i32 = int; using i64 = long long; using u16= unsigned short; using u32 = unsigned int; using u64 = unsigned long long;using f32 = float; using f64 = double; using f128 = long double;
using pii = std::pair<i32, i32>; using pll = std::pair<i64, i64>; using pil = std::pair<i32, i64>; using pli = std::pair<i64, i32>;
template<class T> using V = std::vector<T>;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); } template <typename T> inline void reads(T begin, T end){ while(begin != end) { read(*begin); begin++; } }
void solve(); void init();
int TESTCASE = 1; int main() { init(); for(int i = 1; i <= TESTCASE; i++){ solve(); } return 0;}
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#define TO_STRING(type) void _to_string_##type(std::ostream& buffer, const type& value); std::ostream& operator<<(std::ostream& buff, const type& value){ _to_string_##type(buff, value); return buff; }\
  void _to_string_##type(std::ostream& buffer, const type& value)
template<class T> T lowbit(T x) { return (-x) & x; };
template<class T> T highbit(T x) { while(x != lowbit(x)) x -= lowbit(x); return x; }
template<class T> T fstTrue(T l, T r, std::function<bool(T)> check){ assert(l <= r); while(l < r){ T mid = l + (r - l) / 2; if(check(mid)) r = mid; else l = mid + 1; } return r; }
template<class T> T lstTrue(T l, T r, std::function<bool(T)> check){ assert(l <= r); while(l < r){ T mid = l + (r - l + 1)/2; if(check(mid)) l = mid; else r = mid - 1; } return l; }
template<class T> T gcd(T a, T b) { return std::__gcd(a, b); }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; };
template<const int T> struct MInt { const static int mod = T; int x; MInt(int x = 0) : x(x % mod) {} MInt(long long x) : x(int(x % mod)) {} MInt(unsigned long long x): x(int(x % mod)){} int val() { return x; } MInt operator + (const MInt &a) const { int x0 = x + a.x; return MInt(x0 < mod ? x0 : x0 - mod); } MInt operator - (const MInt &a) const { int x0 = x - a.x; return MInt(x0 < 0 ? x0 + mod : x0); } MInt operator * (const MInt &a) const { return MInt(1LL * x * a.x % mod); } MInt operator / (const MInt &a) const { return *this * a.inv(); } bool operator == (const MInt &a) const { return x == a.x; }; bool operator != (const MInt &a) const { return x != a.x; }; void operator += (const MInt &a) { x += a.x; if (x >= mod) x -= mod; } void operator -= (const MInt &a) { x -= a.x; if (x < 0) x += mod; } void operator *= (const MInt &a) { x = 1LL * x * a.x % mod; } void operator /= (const MInt &a) { *this = *this / a; } friend MInt operator + (int y, const MInt &a){ int x0 = y + a.x; return MInt(x0 < mod ? x0 : x0 - mod); } friend MInt operator - (int y, const MInt &a){ int x0 = y - a.x; return MInt(x0 < 0 ? x0 + mod : x0); } friend MInt operator * (int y, const MInt &a){ return MInt(1LL * y * a.x % mod);} friend MInt operator / (int y, const MInt &a){ return MInt(y) / a;} friend std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.x;} friend std::istream &operator>>(std::istream &is, MInt &t){return is >> t.x;} MInt pow(int64_t n) const { MInt res(1), mul(x); while(n){ if (n & 1) res *= mul; mul *= mul; n >>= 1; } return res; } MInt inv() const { int a = x, b = mod, u = 1, v = 0; while (b) { int t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); } if (u < 0) u += mod; return u; } };
#ifdef LOCAL
#define debug_do if(true)
#else
#define debug_do if(false)
#endif
#define debug(...) debug_do std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#define maxnum(type) std::numeric_limits<type>::max()
#define minnum(type) std::numeric_limits<type>::min()
#define pb push_back
#define pf push_front
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define all1(x) ++(x).begin(), (x).end()
#define rall1(x) (x).rbegin(), --(x).rend()
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
template<class R, class A> R mmax(R x, A y){ return std::max(x, (R) y); } template<class R, class A, class... AS> R mmax(R x, A xx, AS... xxs){ return std::max(x, mmax((R)xx, xxs...));  }
template<class R, class A> R mmin(R x, A y){ return std::min(x, (R) y); } template<class R, class A, class... AS> R mmin(R x, A xx, AS... xxs){ return std::min(x, mmin((R)xx, xxs...));  }
using std::cout; using std::cin; using std::endl;
#define endl "\n"
// clang-format on
#define int i64
// using i128 = __int128;
void init() {
  read(TESTCASE);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  // std::cout.tie(nullptr); std::cin >> TESTCASE;
}
const int maxn = 500 + 17;
char mp[maxn][maxn];
bool vis[maxn][maxn];
char color[maxn][maxn];
int cw[maxn], rw[maxn];
int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;

bool found = false;
char opposite_color(char x) {
  if (x == 'W')
    return 'B';
  else
    return 'W';
  assert(0);
}

bool check() {
  for (int i = 0; i < n; i++) {
    if (rw[i] != 0) return false;
  }
  for (int i = 0; i < m; i++) {
    if (cw[i] != 0) return false;
  }
  return true;
}

void dfs(int x, int y, int cnt = 1) {
  if (vis[x][y]) return;
  if (x < 0 || y < 0 || x >= n || y >= m) return;
  vis[x][y] = true;

  bool finish = cnt == n * m;

  debug(x, y);

  auto progress = [&finish, &cnt](int xx, int yy) {
    if (finish) {
      if (check()) {
        found = true;
      }
    } else {
      for (auto [ofx, ofy] : dir) {
        dfs(xx + ofx, yy + ofy, cnt + 1);
      }
    }
  };

  if (mp[x][y] != '.' && color[x][y] == '.') {
    if (mp[x][y] == 'L') {
      color[x][y] = 'W';
      color[x][y + 1] = 'B';
      cw[y + 1]--;
      cw[y]++;

      progress(x, y);
      if (found) return;

      cw[y] -= 2;
      cw[y + 1] += 2;
      color[x][y] = 'B';
      color[x][y + 1] = 'W';

      progress(x, y);
      if (found) return;
      cw[y]++;
      cw[y + 1]--;
      color[x][y] = '.';
      color[x][y + 1] = '.';
    }
    if (mp[x][y] == 'U') {
      color[x][y] = 'W';
      color[x + 1][y] = 'B';

      rw[x]++;
      rw[x + 1]--;
      progress(x, y);

      if (found) return;
      color[x][y] = 'B';
      color[x + 1][y] = 'W';

      rw[x] -= 2;
      rw[x + 1] += 2;

      progress(x, y);
      if (found) return;
      rw[x]++;
      rw[x + 1]--;
      color[x][y] = '.';
      color[x + 1][y] = '.';
    }

  } else {
    progress(x, y);
    if (found) return;
  }

  vis[x][y] = false;
}

void solve() {
  cin >> n >> m;
  V<std::string> mp(n);
  for (auto &s : mp) cin >> s;
  V<i64> row(n), col(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == 'L') {
        col[j]++;
      }
      if (mp[i][j] == 'U') {
        row[i]++;
      }
    }
  }
  bool pos = true;
  for (auto &i : row) {
    if (i & 1) pos = false;
    i /= 2;
  }
  for (auto &i : col) {
    if (i & 1) pos = false;
    i /=2;
  }
  if (!pos) {
    cout << "-1\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == 'L') {
        if (col[j]) {
          mp[i][j] = 'W';
          mp[i][j + 1] = 'B';
          col[j]--;
        } else {
          mp[i][j] = 'B';
          mp[i][j + 1] = 'W';
        }
      }
      else if (mp[i][j] == 'U') {
        if (row[i]) {
          mp[i][j] = 'W';
          mp[i + 1][j] = 'B';
          row[i]--;
        } else {
          mp[i][j] = 'B';
          mp[i + 1][j] = 'W';
        }
      }
    }
  }
  for (auto s : mp) cout << s << "\n";
}
