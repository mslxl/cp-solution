#include <stdio.h>
long long A[100007], n, x;
int main() {
  scanf("%lld %lld", &n, &x);
  for (long long i = 1; i <= n; ++i)
    scanf("%lld", &A[i]);
  long long left = 1, right = n, mid;
  while (left < right) {
    mid = left + (right - left) / 2;
    if (A[mid] == x) {
      printf("%lld", mid);
      return 0;
    } else if (A[mid] > x)
      right = mid;
    else
      left = mid;
  }
}
