#include <cstdio>
typedef long long ll;
ll x, a, b;
ll kill = 0;
int main() {
  scanf("%lld%lld%lld", &x, &a, &b);
  char c;
  while (~scanf("%c", &c)) {
    if (c == '1') {
      if (x >= a) {
        kill++;
        x -= a;
      } else {
        x += b;
      }
    } else if (c == '0') {
      x += b;
    }
  }
  printf("%lld", kill);
}
