#include <bits/stdc++.h>
using namespace std;

string s[4];

int main() {
  int n;
  cin >> n;
  double res = 0.0;
  for (int i = 0; i < 1; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 1; i++) {
    double buff = 0;
    res = 0;
    for (int j = 0; j < n; j++) {
      switch (s[i][j]) {
      case '.':
        if (buff >= 0.5) {
          res += 0.5;
          buff -= 0.5;
        } else {
          res += 1;
        }
        break;
      case 'w':
        if (buff >= 1) {
          res += 1;
          buff -= 1;
        } else if (buff == 0.5) {
          res += 1.5;
          buff = 0;
        } else {
          res += 2;
        }
        break;
      case '>':
        buff = 5;
        buff -= 0.5;
        res += 0.5;
        break;
      case 's':
        res += 1;
        if (buff >= 1) {
          buff -= 1;
        } else {
          buff = 0;
        }
        if (buff != 0) {
          res += 0.5;
          buff -= 0.5;
        } else {
          res += 1;
        }
        break;
      case 'm':
        res += 2;
        if (buff > 2) {
          buff -= 2;
        } else {
          buff = 0;
        }
        if (buff != 0) {
          res += 0.5;
          buff -= 0.5;
        } else {
          res += 1;
        }
        break;
      }
    }
    printf("%.1f ", res);
  }
  return 0;
}