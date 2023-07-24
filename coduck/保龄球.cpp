#include <iostream>

using namespace std;

string s[210];

int hit[210][2], score[210], n = 1, i, res = 0;

int main() {
  while (cin >> s[n]) ++n;
  --n;
  for (i = 1; i <= n; ++i) {
    if (s[i][0] == '/')
      hit[i][0] = 10;
    else if (s[i][1] == '/') {
      hit[i][0] = s[i][0] - '0';
      hit[i][1] = 10 - hit[i][0];
    }
    else {
      hit[i][0] = s[i][0] - '0';
      hit[i][1] = s[i][1] - '0';
    }
  }
  for (i = 10; i; --i) {
    if (s[i][0] == '/')
      score[i] = hit[i + 1][0] +
                 ((s[i + 1].size() < 2) ? hit[i + 2][0] : hit[i + 1][1]) + 10;
    else if (s[i][1] == '/')
      score[i] = hit[i + 1][0] + 10;
    else
      score[i] = hit[i][0] + hit[i][1];
    res += score[i];
  }
  cout << res;
  return 0;
}
