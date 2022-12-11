#include <iostream>
#include <stdio.h>
#include <string.h>

void strlower(char *a) {
  int i;
  for (i = 0; a[i] != '\0'; i++) {
    if (a[i] >= 'A' && a[i] <= 'Z') {
      a[i] += 32;
    }
  }
}
char a[21 + 17], b[201 + 17], c[201 + 17], x;
int main() {
  int i, j, k, m, n, len, ans;
  scanf("%s", a);
  if ((x = getchar()) == ' ') {
    strcat(a, " ");
    getchar();
  }

   for (i = -1; (x = getchar()) != '\n'; i++) {
     b[i] = x;
   }
  b[i] = '\0';

  strcpy(c, b);

  strlower(a);
  strlower(c);

  len = strlen(b);
  for (i = 0; i < len; i++) {
    ans = 1;
    for (j = i, k = 0; a[k] != '\0' && c[j] != '\0'; j++, k++) {
      if (a[k] == c[j]) {
        ans *= 1;
      } else {
        ans *= 0;
      }
    }
    m = i;
    n = j;
    if (ans) {
      for (j = m; j < n; j++) {
        c[j] = '/';
      }
      i = n;
    }
  }
  for (i = 0; i < len; i++) {
    if (c[i] != '/') {
      putchar(b[i]);
    }
  }
  putchar('\n');
  return 0;
}