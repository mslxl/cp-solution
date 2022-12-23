/*
Give a tree with n vertices,each edge has a length(positive integer less than
1001). Define dist(u,v)=The min distance between node u and v. Give an integer
k,for every pair (u,v) of vertices is called valid if and only if dist(u,v) not
exceed k. Write a program that will count how many pairs which are valid for a
given tree.
*/

#include <iostream>

template <typename T>
inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x) {
  char c;
  T f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-')
      f = -1;
  x = (c & 15);
  while (isdigit(c = getchar()))
    x = (x << 1) + (x << 3) + (c & 15);
  x *= f;
}

template <typename T, typename... A> void read(T &value, A &..._t) {
  read(value);
  read(_t...);
}

#define rep(NAME, MAX) for (decltype(MAX) NAME = 0; NAME < MAX; i++)
#define rep1(NAME, MAX) for (decltype(MAX) NAME = 1; NAME <= MAX; i++)
#define repv0(NAME, START) for (decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for (decltype(START) NAME = START; NAME >= 1; NAME--)

const int maxn = 1e4+ 17;
struct edge{
  int to,w;
  int next;
} e[maxn];

int head[maxn], eid = 0;
int parent[maxn];
void add_edge(int u, int v, int w){
  eid++;
  parent[v] = u;
  e[eid].to = v;
  e[eid].w = w;
  e[eid].next = head[u];
  head[u] = eid;
}

int n, k;
int main() {
  read(n, k);
  rep(i, n-1){
    int u,v,l;
    read(u,v,l);
    add_edge(u, v, l);
  }
  return 0;
}
