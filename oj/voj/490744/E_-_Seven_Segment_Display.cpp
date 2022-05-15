#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;

int HexMap[300];
char a[10], b[10], c[10];

struct Value {
  ll val, num;
} dp[10];

Value dfs(int pos, int h, int limit) {
  if (pos == 0) {
    Value e;
    e.num = 1, e.val = 0;
    return e;
  }
  if (!limit && dp[pos].num != -1)
    return dp[pos];
  char upp = limit ? c[pos] : 'F';
  int up;
  if (upp >= '0' && upp <= '9')
    up = upp - '0';
  else
    up = upp - 'A' + 10;
  Value ans;
  ans.num = 0, ans.val = 0;
  for (int i = 0; i <= up; i++) {
    char x;
    if (i <= 9)
      x = '0' + i;
    else
      x = 'A' + i - 10;
    Value e = dfs(pos - 1, i, limit && i == up);
    ans.num += e.num;
    ans.val += e.val + e.num * HexMap[x];
  }
  if (!limit)
    dp[pos] = ans;
  return ans;
}

void cal2Hex(ll x) {
  int pos = 9;
  for (int i = 1; i <= 8; i++) {
    int f = x % 16;
    if (f >= 0 && f <= 9)
      b[--pos] = '0' + f;
    else
      b[--pos] = 'A' + f - 10;
    x /= 16;
  }
}

ll solve(const char* ch) {
  for (int i = 0; i < 10; i++)
    dp[i].num = -1;
  int pos = 0;
  for (int i = 8; i >= 1; i--) {
    c[++pos] = ch[i];
  }
  return dfs(pos, -1, 1).val;
}

void initHexMap() {
  HexMap['0'] = 6;
  HexMap['1'] = 2;
  HexMap['2'] = 5;
  HexMap['3'] = 5;
  HexMap['4'] = 4;
  HexMap['5'] = 5;
  HexMap['6'] = 6;
  HexMap['7'] = 3;
  HexMap['8'] = 7;
  HexMap['9'] = 6;
  HexMap['A'] = 6;
  HexMap['B'] = 5;
  HexMap['C'] = 4;
  HexMap['D'] = 5;
  HexMap['E'] = 5;
  HexMap['F'] = 4;
}

void solve() {
  ll maxx = 1;
  for (int i = 1; i <= 8; i++)
    maxx *= 16;
  ll p;
  scanf("%lld%s", &p, a + 1);
  ll n = 0;
  int flag = 0;
  for (int i = 1; i <= 8; i++) {
    if (a[i] == '0')
      flag++;
    if (a[i] >= '0' && a[i] <= '9')
      n = n * 16 + a[i] - '0';
    else
      n = n * 16 + a[i] - 'A' + 10;
  }
  if (flag == 8) {
    cal2Hex(n + p - 1);
    printf("%lld\n", solve(b));
  } else {
    if (n + p - 1 > maxx) {
      cal2Hex(n - 1);
      ll ans = solve("FFFFFFFFF") - solve(b);
      cal2Hex(n + p - 1 - maxx);
      ans += solve(b);
      printf("%lld\n", ans);
    } else {
      cal2Hex(n + p - 1);
      ll num1 = solve(b);
      cal2Hex(n - 1);
      ll num2 = solve(b);
      printf("%lld\n", num1 - num2);
    }
  }
}

int main() {
  initHexMap();
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}