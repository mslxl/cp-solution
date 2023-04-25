
#include <bits/stdc++.h>

template <typename T>
void read(T& value) {
  value = 0;
  char ch = getchar();
  bool flag = false;
  while (!std::isdigit(ch)) {
    if (ch == '-')
      flag = true;
    ch = getchar();
  }
  while (std::isdigit(ch)) {
    value = value * 10 + (ch - '0');
    ch = getchar();
  }
  if (flag)
    value *= -1;
}

template <typename T, typename... A>
inline void read(T& value, A&... _t) {
  read(value);
  read(_t...);
}
const int maxn = 2e5 + 5;  
int v[maxn];               
struct L                   
{
  int x;                                       
  int y1, y2;                                  
  int state;                                   
  bool operator<(L oth) { return x < oth.x; }  
} line[maxn];
struct Node  
{
  int l, r;        
  int cover;       
  long long len;   
} sgt[maxn << 3];  
inline int ls(int k) {
  return k << 1;
}  
inline int rs(int k) {
  return k << 1 | 1;
}  
inline void pushup(int k)  
{
  if (sgt[k].cover)
    sgt[k].len = sgt[k].r - sgt[k].l;
  else
    sgt[k].len = sgt[ls(k)].len + sgt[rs(k)].len;
}
void build(int l, int r, int k = 1) {
  sgt[k].l = v[l], sgt[k].r = v[r];  
  if (r - l <= 1)
    return;  
  int m = (l + r) >> 1;
  build(l, m, ls(k));
  build(m, r, rs(k));
}
void modify(int x, int y, int z, int k = 1) {
  int l = sgt[k].l, r = sgt[k].r;
  if (x <= l && y >= r) {
    sgt[k].cover += z;
    pushup(k);  
    return;
  }
  if (x < sgt[ls(k)].r)
    modify(x, y, z, ls(k));  
  if (y > sgt[rs(k)].l)
    modify(x, y, z, rs(k));  
  pushup(k);
}
int main(int argc, char const* argv[]) {
  int a, b, c, d, n;
  read(n);
  for (int i = 1; i <= n; i++)  
  {
    read(a, b, c, d);
    v[i] = b, v[n + i] = d;
    line[i] = (L){a, b, d, 1}, line[n + i] = (L){c, b, d, -1};
  }
  std::sort(v + 1, v + 1 + (n << 1));
  std::sort(line + 1, line + 1 + (n << 1));
  build(1, n << 1);
  unsigned long long ans = 0;  
  for (int i = 1; i <= n << 1; i++) {
    ans += sgt[1].len * (line[i].x - line[i - 1].x);  
    modify(line[i].y1, line[i].y2, line[i].state);
  }
  std::cout << ans;
  return 0;
}