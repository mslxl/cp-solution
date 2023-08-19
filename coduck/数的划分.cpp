
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <stdio.h>
#include <cstdlib>
#include <set>
#define ll long long
using namespace std;
long long n;
long long m;
long long arr[4000000];
ll s[4000000];
ll brr[4000000];
ll num = 0;
int finnd(int x, int k, int j) {
  if (k == 1) {
    num++;
    return 0;
  }
  int a, b;
  a = x / k;
  b = x % k;
  if (b > 0)
    a++;
  j = x - k + 1 < j ? x - k + 1 : j;
  for (int i = a; i <= j; i++) {
    finnd(x - i, k - 1, i);
  }
  return 0;
}
int main() {
  cin >> n >> m;
  finnd(n, m, n);
  cout << num << endl;
  return 0;
}