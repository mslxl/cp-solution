#include <cstdio>
#include <cstring>
using namespace std;
#define MOD 10007
bool prime[1000005];
int p[1000005], ans, cnt, kase, a, b;
int main() {
  memset(prime, 1, sizeof(prime));
  prime[1] = 0;
  for (int i = 2; i <= 1000000; i++)
    if (prime[i]) {
      p[++p[0]] = i;
      if (i <= 1000)
        for (int j = i * i; j <= 1000000; prime[j] = 0, j += i)
          ;
    }
  for (; scanf("%d%d", &a, &b) != EOF;) {
    ans = 1;
    if (prime[a]) {
      ans = (ans * b + 1) % MOD;
      ans = (ans * (ans + 1) / 2) % MOD;
      ans = (ans * ans) % MOD;
    } else
      for (int i = 1; (i <= p[0]) && (a > 1); i++) {
        cnt = 0;
        if (prime[a]) {
          cnt = 1;
          a = 1;
        } else
          for (; a % p[i] == 0; ++cnt, a /= p[i])
            ;
        cnt = (cnt * b + 1) % MOD;
        cnt = (cnt * (cnt + 1) / 2) % MOD;
        cnt = (cnt * cnt) % MOD;
        ans = (ans * cnt) % MOD;
      }
    printf("Case %d: %d\n", ++kase, ans);
  }
  return 0;
}