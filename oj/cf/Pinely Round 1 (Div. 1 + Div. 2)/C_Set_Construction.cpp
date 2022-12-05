#include <bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;
using ld = long double;

// ------------ Minify with Regex "^\s*(?!#)(.*)\n" -> "$1 " ------------
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#else
#define debug(...) do {} while (0)
#endif
// Codes Below

const int maxn = 1e6; //顶点数
const int maxm = 2e6; //边数

struct edge{
	int to;
	int next;
}e[maxm * 2 + 1];

int eid = 0;
int head[maxn];
int indegree[maxn];

void add_edge(int u,int v){
	eid++;
	edge& ed = e[eid];
	ed.to = v;
	ed.next = head[u];
	head[u] = eid;
}

void clear_graph(){
  std::memset(head, 0, sizeof(head));
  eid = 0;
  std::memset(indegree, 0, sizeof(indegree));
}


void solve(const std::size_t testcase) {
  clear_graph();
  int n;
  std::cin >> n;

  std::string line;
  std::getline(std::cin, line);
  for(int i = 1; i <= n; i++){
    std::getline(std::cin, line);
    line = "$" + line;
    for(int j = 1; j <= n; j++){
      if(line[j] == '1'){
        debug(i, " > ", j);
        add_edge(i,j);
        indegree[j]++;
      }
    }
  }
 if(n==1){
    std::cout << "1 1\n";
    return;
  }
  std::vector<int> leaf;
  for(int i = 1; i <n;i++){
    if(indegree[i] == 0){
      leaf.push_back(i);
    }
  }
  int cnt = 1;
  debug(leaf);
  std::vector<std::set<int>> ans(n+1);
  for(auto &l:leaf){
    ans[l].insert(cnt++);
  }

  std::queue<int> que;
  for(auto &l:leaf){
    que.push(l);
  }

  while(!que.empty()){
    const int u = que.front();
    que.pop();
    for(int i = head[u]; i; i = e[i].next){
      const int v = e[i].to;
      debug(u, "-b->", v);
      if(ans[v].empty()){
        ans[v].insert(cnt++);
      }
      ans[v].insert(ans[u].begin(), ans[u].end());
      que.push(v);
    }
  }

  for(int i = 1; i <= n; i++){
    std::cout << ans[i].size();
    for(auto k: ans[i]){
      std::cout << " " << k;
    }
    std::cout << "\n";
  }

  debug("----------");
}

int main() {
#ifdef ONLINE_JUDGE
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  int t;
  std::cin >> t;
  for (std::size_t i = 1; i <= t; i++) {
    solve(t);
  }

  return 0;
}