#include <bits/stdc++.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int c = a + b;
  printf("%d+%d=%d\n", a, b, c);
  printf("%7d\n", a);
  printf("+%6d\n", b);
  printf("-------\n");
  printf("%7d", c);
  return 0;
}
