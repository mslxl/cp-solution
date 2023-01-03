#include <cmath>
#include <cstdio>
typedef long long ll;
int main() {
  int n;
  scanf("%d", &n);
  int *arr = new int[n + 1];
  for (int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
  }

  ll result = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      result += std::abs(arr[i] + arr[j] - 1000);
    }
  }

  printf("%lld", result);

  return 0;
}
