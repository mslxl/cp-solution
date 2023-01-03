#include <cstdio>
int main() {
  char c;
  long long tm[10] = {0};
  while (~scanf("%c", &c)) {
    if (c != '5' && c > '0' && c <= '9') {
      tm[c - '0']++;
      tm[5]++;
    }
  }
  for (int i = 1; i <= 9; i++) {
    printf("%lld ", tm[i]);
  }
}
