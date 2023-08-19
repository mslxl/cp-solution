#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const char C = 'C', S = 'S', P = 'P';
int n, m, ans, cost, cntS[N], preC[N], sufC[N];
char s[N];
bool extend(int l, int &r) {
  if (r + 1 > m) //越界，不可行
    return false;
  if (s[r + 1] == C) { // 无代价增长
    r++;
    return true;
  }
  if (s[r + 1] == P) { // 代价 + 2
    if (cost + 2 <= n) {
      r++, cost += 2;
      return true;
    }
    return false;
  }

  if (cntS[r] - cntS[max(l - 1, preC[r + 1])] == 0) {
    if (cost + 1 <= n) {
      r++, cost++;
      return true;
    }
    return false;
  }
  r++;
  return true;
}
int main() {
  std::cin >> n >> (s + 1);
  m = strlen(s + 1);
  sufC[m + 1] = m + 1;
  for (int i = 1; i <= m; i++)
    cntS[i] += cntS[i - 1] + (s[i] == S);
  for (int i = 1; i <= m; i++)
    preC[i] = (s[i] == C) ? i : preC[i - 1]; // 上一个 C 的位置
  for (int i = m; i >= 1; i--)
    sufC[i] = (s[i] == C) ? i : sufC[i + 1]; // 下一个 C 的位置
  int best_l, best_r;
  for (int l = 1, r = 0; l <= m; l++) {
    r = max(r, l - 1);
    while (extend(l, r)){}
    if(r-l+1 > ans){
      best_l = l;
      best_r = r;
    }
    
    ans = max(ans, r - l + 1);
    if (r < l)
      continue;
    if (s[l] == P)
      cost -= 2;
    else if (s[l] == S && cntS[min(r, sufC[l])] - cntS[l] == 0)
      cost--;
  }
  #ifdef DEBUG
  std::cerr << best_l << ", " << best_r  << ": ";
  for(int i = best_l; i <= best_r; i++) std::cerr << s[i];
  std::cerr << std::endl;
  #endif

  std::cout << ans;
  return 0;
}