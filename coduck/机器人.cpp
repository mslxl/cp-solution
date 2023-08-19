#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
#include <cstdio>
#include <cstring>
char s[5010];
int T, L, x, y;
vector<vector<ll>> v(1000006);
vector<bool> vis(1000006);
vector<ll> dep(1000006);
vector<ll> num(1000006);

bool cmp(ll a, ll b) { return a > b; }

int main() {
  scanf("%s%d", s, &T);
  L = strlen(s);
  for (int i = 0; i < L; i++) {
    switch (s[i]) {
    case 'E':
      x++;
      break;
    case 'S':
      y--;
      break;
    case 'W':
      x--;
      break;
    case 'N':
      y++;
      break;
    }
  }
  x = x * (T / L);
  y = y * (T / L);
  for (int i = 0; i < T % L; i++) {
    switch (s[i]) {
    case 'E':
      x++;
      break;
    case 'S':
      y--;
      break;
    case 'W':
      x--;
      break;
    case 'N':
      y++;
      break;
    }
  }
  printf("%d %d", x, y);
  return 0;
}