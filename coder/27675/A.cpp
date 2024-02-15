// Problem: Sort Points by Argument
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/27675/A
// Memory Limit: 524288 MB
// Time Limit: 10000 ms
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
using std::cout; using std::cin; using std::endl;
#define endl "\n"
// clang-format on
// using i128 = __int128; 
void init(){
 // read(TESTCASE);
 // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
 // std::cin >> TESTCASE; 
}

using point_t=long long;  //全局数据类型

constexpr point_t eps=1e-8;
constexpr point_t INF=std::numeric_limits<point_t>::max();
constexpr long double PI=3.1415926535897932384l;

// 点与向量
template<typename T> struct point
{
    T x,y;

    bool operator==(const point &a) const {return (abs(x-a.x)<=eps && abs(y-a.y)<=eps);}
    bool operator<(const point &a) const {if (abs(x-a.x)<=eps) return y<a.y-eps; return x<a.x-eps;}
    bool operator>(const point &a) const {return !(*this<a || *this==a);}
    point operator+(const point &a) const {return {x+a.x,y+a.y};}
    point operator-(const point &a) const {return {x-a.x,y-a.y};}
    point operator-() const {return {-x,-y};}
    point operator*(const T k) const {return {k*x,k*y};}
    point operator/(const T k) const {return {x/k,y/k};}
    T operator*(const point &a) const {return x*a.x+y*a.y;}  // 点积
    T operator^(const point &a) const {return x*a.y-y*a.x;}  // 叉积，注意优先级
    int toleft(const point &a) const {const auto t=(*this)^a; return (t>eps)-(t<-eps);}  // to-left 测试
    T len2() const {return (*this)*(*this);}  // 向量长度的平方
    T dis2(const point &a) const {return (a-(*this)).len2();}  // 两点距离的平方

    // 涉及浮点数
    long double len() const {return sqrtl(len2());}  // 向量长度
    long double dis(const point &a) const {return sqrtl(dis2(a));}  // 两点距离
    long double ang(const point &a) const {return acosl(max(-1.0l,min(1.0l,((*this)*a)/(len()*a.len()))));}  // 向量夹角
    point rot(const long double rad) const {return {x*cos(rad)-y*sin(rad),x*sin(rad)+y*cos(rad)};}  // 逆时针旋转（给定角度）
    point rot(const long double cosr,const long double sinr) const {return {x*cosr-y*sinr,x*sinr+y*cosr};}  // 逆时针旋转（给定角度的正弦与余弦）
};

using Point=point<point_t>;

// 极角排序
struct argcmp
{
    bool operator()(const Point &a,const Point &b) const
    {
        const auto quad=[](const Point &a)
        {
            if (a.y<-eps) return 1;
            if (a.y>eps) return 4;
            if (a.x<-eps) return 5;
            if (a.x>eps) return 3;
            return 2;
        };
        const int qa=quad(a),qb=quad(b);
        if (qa!=qb) return qa<qb;
        const auto t=a^b;
        // if (abs(t)<=eps) return a*a<b*b-eps;  // 不同长度的向量需要分开
        return t>eps;
    }
};


void solve() {
	int n;
  std::cin >> n;
  std::vector<Point> p(n);
  for(int i = 0 ; i < n; i++){
    std::cin >> p[i].x >> p[i].y;
  }
  std::sort(all(p), argcmp());
  for(int i = 0; i < n; i++){
    std::cout << p[i].x << " " << p[i].y<< "\n";
  }
}
