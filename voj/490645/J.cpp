#include <bits/stdc++.h>
using namespace std;
string s;
int ans[100005];
int k;
void cot() {
  if (k == 0 || k == 1 || k == 2) {
    cout << "-1" << endl;
    return;
  } else if (!(k % 4)) {
    for (int i = 1; i <= k / 4; i++) {
      if (s[i - 1] == '1')
        ans[i] = 3;
      else
        ans[i] = 1;
      if (s[k - i] == '1')
        ans[k - i + 1] = 3;
      else
        ans[k - i + 1] = 1;
    }
    for (int i = k / 4 + 1; i <= k / 2; i++) {
      if (s[i - 1] == '1')
        ans[i] = 4;
      else
        ans[i] = 2;
      if (s[k - i] == '1')
        ans[k - i + 1] = 4;
      else
        ans[k - i + 1] = 2;
    }
  } else if (k % 4 == 3) {
    if (s[0] == '1')
      ans[1] = 3;
    else
      ans[1] = 1;
    if (s[1] == '1')
      ans[2] = 3;
    else
      ans[2] = 1;
    if (s[2] == '1')
      ans[3] = 4;
    else
      ans[3] = 2;
    for (int i = 4; i <= 3 + (k - 3) / 4; i++) {
      if (s[i - 1] == '1')
        ans[i] = 3;
      else
        ans[i] = 1;
      if (s[k - i + 3] == '1')
        ans[k - i + 4] = 3;
      else
        ans[k - i + 4] = 1;
      // cout<<"*"<<endl;
    }
    for (int i = 3 + (k - 3) / 4 + 1; i <= k - (k - 3) / 2; i++) {
      if (s[i - 1] == '1')
        ans[i] = 4;
      else
        ans[i] = 2;
      if (s[k - i + 3] == '1')
        ans[k - i + 4] = 4;
      else
        ans[k - i + 4] = 2;
    }
  } else {
    cout << "-1" << endl;
    return;
  }
  for (int i = 1; i <= k; i++)
    cout << ans[i];
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    memset(ans, 0, sizeof(ans));
    cin >> k;
    cin >> s;
    cot();
  }
  return 0;
}