// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); } template <typename T> inline void reads(T begin, T end){ while(begin != end) { read(*begin); begin++; } }
void solve(const std::size_t testcase);
int main() {
  std::size_t t = 1;
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  // read(t); // std::cin >> t;
  for(std::size_t i = 1; i <= t; i++) solve(t);
  return 0;
}
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

struct BigIntTiny {
    int sign;
    std::vector<int> v;

    BigIntTiny() : sign(1) {}
    BigIntTiny(const std::string &s) { *this = s; }
    BigIntTiny(int v) {
        char buf[21];
        sprintf(buf, "%d", v);
        *this = buf;
    }
    void zip(int unzip) {
        if (unzip == 0) {
            for (int i = 0; i < (int)v.size(); i++)
                v[i] = get_pos(i * 4) + get_pos(i * 4 + 1) * 10 + get_pos(i * 4 + 2) * 100 + get_pos(i * 4 + 3) * 1000;
        } else
            for (int i = (v.resize(v.size() * 4), (int)v.size() - 1), a; i >= 0; i--)
                a = (i % 4 >= 2) ? v[i / 4] / 100 : v[i / 4] % 100, v[i] = (i & 1) ? a / 10 : a % 10;
        setsign(1, 1);
    }
    int get_pos(unsigned pos) const { return pos >= v.size() ? 0 : v[pos]; }
    BigIntTiny &setsign(int newsign, int rev) {
        for (int i = (int)v.size() - 1; i > 0 && v[i] == 0; i--)
            v.erase(v.begin() + i);
        sign = (v.size() == 0 || (v.size() == 1 && v[0] == 0)) ? 1 : (rev ? newsign * sign : newsign);
        return *this;
    }
    std::string to_str() const {
        BigIntTiny b = *this;
        std::string s;
        for (int i = (b.zip(1), 0); i < (int)b.v.size(); ++i)
            s += char(*(b.v.rbegin() + i) + '0');
        return (sign < 0 ? "-" : "") + (s.empty() ? std::string("0") : s);
    }
    bool absless(const BigIntTiny &b) const {
        if (v.size() != b.v.size()) return v.size() < b.v.size();
        for (int i = (int)v.size() - 1; i >= 0; i--)
            if (v[i] != b.v[i]) return v[i] < b.v[i];
        return false;
    }
    BigIntTiny operator-() const {
        BigIntTiny c = *this;
        c.sign = (v.size() > 1 || v[0]) ? -c.sign : 1;
        return c;
    }
    BigIntTiny &operator=(const std::string &s) {
        if (s[0] == '-')
            *this = s.substr(1);
        else {
            for (int i = (v.clear(), 0); i < (int)s.size(); ++i)
                v.push_back(*(s.rbegin() + i) - '0');
            zip(0);
        }
        return setsign(s[0] == '-' ? -1 : 1, sign = 1);
    }
    bool operator<(const BigIntTiny &b) const {
        return sign != b.sign ? sign < b.sign : (sign == 1 ? absless(b) : b.absless(*this));
    }
    bool operator==(const BigIntTiny &b) const { return v == b.v && sign == b.sign; }
    BigIntTiny &operator+=(const BigIntTiny &b) {
        if (sign != b.sign) return *this = (*this) - -b;
        v.resize(std::max(v.size(), b.v.size()) + 1);
        for (int i = 0, carry = 0; i < (int)b.v.size() || carry; i++) {
            carry += v[i] + b.get_pos(i);
            v[i] = carry % 10000, carry /= 10000;
        }
        return setsign(sign, 0);
    }
    BigIntTiny operator+(const BigIntTiny &b) const {
        BigIntTiny c = *this;
        return c += b;
    }
    void add_mul(const BigIntTiny &b, int mul) {
        v.resize(std::max(v.size(), b.v.size()) + 2);
        for (int i = 0, carry = 0; i < (int)b.v.size() || carry; i++) {
            carry += v[i] + b.get_pos(i) * mul;
            v[i] = carry % 10000, carry /= 10000;
        }
    }
    BigIntTiny operator-(const BigIntTiny &b) const {
        if (b.v.empty() || b.v.size() == 1 && b.v[0] == 0) return *this;
        if (sign != b.sign) return (*this) + -b;
        if (absless(b)) return -(b - *this);
        BigIntTiny c;
        for (int i = 0, borrow = 0; i < (int)v.size(); i++) {
            borrow += v[i] - b.get_pos(i);
            c.v.push_back(borrow);
            c.v.back() -= 10000 * (borrow >>= 31);
        }
        return c.setsign(sign, 0);
    }
    BigIntTiny operator*(const BigIntTiny &b) const {
        if (b < *this) return b * *this;
        BigIntTiny c, d = b;
        for (int i = 0; i < (int)v.size(); i++, d.v.insert(d.v.begin(), 0))
            c.add_mul(d, v[i]);
        return c.setsign(sign * b.sign, 0);
    }
    BigIntTiny operator/(const BigIntTiny &b) const {
        BigIntTiny c, d;
        d.v.resize(v.size());
        double db = 1.0 / (b.v.back() + (b.get_pos((unsigned)b.v.size() - 2) / 1e4) +
                           (b.get_pos((unsigned)b.v.size() - 3) + 1) / 1e8);
        for (int i = (int)v.size() - 1; i >= 0; i--) {
            c.v.insert(c.v.begin(), v[i]);
            int m = (int)((c.get_pos((int)b.v.size()) * 10000 + c.get_pos((int)b.v.size() - 1)) * db);
            c = c - b * m, c.setsign(c.sign, 0), d.v[i] += m;
            while (!(c < b))
                c = c - b, d.v[i] += 1;
        }
        return d.setsign(sign * b.sign, 0);
    }
    BigIntTiny operator%(const BigIntTiny &b) const { return *this - *this / b * b; }
    bool operator>(const BigIntTiny &b) const { return b < *this; }
    bool operator<=(const BigIntTiny &b) const { return !(b < *this); }
    bool operator>=(const BigIntTiny &b) const { return !(*this < b); }
    bool operator!=(const BigIntTiny &b) const { return !(*this == b); }
};
void solve(const std::size_t testcase) {
  std::string a,b;
  std::cin >> a >> b;
  BigIntTiny c(a), d(b);
  std::cout << (c/d).to_str();
}
