// Problem: C. Another Permutation Problem
// Contest: Codeforces - Codeforces Round 892 (Div. 2)
// URL: https://codeforces.com/contest/1859/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
// clang-format off
#include <bits/stdc++.h> 
using i16 = short; using i32 = int; using i64 = long long; using u16= unsigned short; using u32 = unsigned int; using u64 = unsigned long long;using f32 = float; using f64 = double; using f128 = long double;
using pii = std::pair<i32, i32>; using pll = std::pair<i64, i64>; using pil = std::pair<i32, i64>; using pli = std::pair<i64, i32>;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); } template <typename T> inline void reads(T begin, T end){ while(begin != end) { read(*begin); begin++; } }
void solve(); void init();
int TESTCASE = 1; int main() { init(); for(int i = 1; i <= TESTCASE; i++){ solve(); if(i != TESTCASE) std::cout << "\n"; } return 0;}
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#define TO_STRING(type) void _to_string_##type(std::ostream& buffer, const type& value); std::ostream& operator<<(std::ostream& buff, const type& value){ _to_string_##type(buff, value); return buff; }\
  void _to_string_##type(std::ostream& buffer, const type& value)
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
#define mk std::make_pair
#define mt std::make_tuple
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define all1(x) ++(x).begin(), (x).end()
#define rall1(x) (x).rbegin(), --(x).rend()
#define mmax(a,  b) a = std::max(a, (decltype(a)) b);
#define mmin(a, b) a = std::min(a, (decltype(a)) b);
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
// clang-format on
#define int i64
// using i128 = __int128;
void init() {
  read(TESTCASE);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  // std::cout.tie(nullptr); std::cin >> TESTCASE;
}
int ans[] = {
    2,       7,       17,      35,      62,      100,     152,     219,
    303,     406,     530,     678,     851,     1051,    1280,    1540,
    1834,    2163,    2529,    2934,    3380,    3869,    4403,    4985,
    5616,    6298,    7033,    7823,    8670,    9576,    10544,   11575,
    12671,   13834,   15066,   16369,   17745,   19196,   20724,   22332,
    24021,   25793,   27650,   29594,   31627,   33751,   35968,   38280,
    40690,   43199,   45809,   48522,   51340,   54265,   57299,   60444,
    63702,   67075,   70565,   74175,   77906,   81760,   85739,   89845,
    94080,   98446,   102945,  107579,  112350,  117260,  122312,  127507,
    132847,  138334,  143970,  149757,  155697,  161792,  168044,  174455,
    181027,  187762,  194662,  201730,  208967,  216375,  223956,  231712,
    239645,  247757,  256050,  264526,  273187,  282035,  291072,  300300,
    309722,  319339,  329153,  339166,  349380,  359797,  370419,  381248,
    392286,  403535,  414997,  426674,  438568,  450681,  463015,  475573,
    488356,  501366,  514605,  528075,  541778,  555716,  569891,  584305,
    598960,  613858,  629001,  644391,  660030,  675920,  692064,  708463,
    725119,  742034,  759210,  776649,  794353,  812324,  830564,  849075,
    867859,  886918,  906254,  925869,  945765,  965944,  986408,  1007160,
    1028201, 1049533, 1071158, 1093078, 1115295, 1137811, 1160628, 1183748,
    1207173, 1230905, 1254946, 1279298, 1303963, 1328943, 1354240, 1379856,
    1405794, 1432055, 1458641, 1485554, 1512796, 1540369, 1568275, 1596516,
    1625094, 1654011, 1683269, 1712870, 1742816, 1773109, 1803751, 1834744,
    1866090, 1897791, 1929849, 1962267, 1995046, 2028188, 2061695, 2095569,
    2129812, 2164426, 2199413, 2234775, 2270514, 2306632, 2343131, 2380013,
    2417280, 2454934, 2492977, 2531411, 2570238, 2609460, 2649080, 2689099,
    2729519, 2770342, 2811570, 2853205, 2895249, 2937704, 2980572, 3023855,
    3067555, 3111674, 3156214, 3201177, 3246565, 3292380, 3338624, 3385299,
    3432407, 3479950, 3527930, 3576350, 3625211, 3674515, 3724264, 3774460,
    3825105, 3876201, 3927750, 3979754, 4032215, 4085135, 4138516, 4192360,
    4246669, 4301445, 4356690, 4412406, 4468595, 4525259, 4582400, 4640020,
    4698122, 4756707, 4815777, 4875334, 4935380, 4995917, 5056947, 5118472,
    5180494};
void solve() {
  int n;
  read(n);

  std::cout << ans[n - 2];
}
