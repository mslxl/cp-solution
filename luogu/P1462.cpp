//通往奥格瑞玛的道路
#include<bits/stdc++.h>
constexpr int maxm = 5 * 1e4 + 17;
constexpr int maxn = 1e4 + 17;
int n,m,b;
std::vector<int> f;


struct road{
  int to;
  int next;
  int damage;
} e[maxm];
int eid = 0;
int head[maxn];




int main(){
  std::cin >> n >> m >> b;
  f.resize(n + 17);
  for(int i = 1; i <= n ;i++){
      std::cin >> f[i];
  }
  return 0;
}