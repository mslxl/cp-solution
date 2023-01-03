#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  if(n % 2 == 0){
    printf("n must be even\n");
    return 0;
  }

  int mid = n / 2;
  for (int i = 0; i < n; i++) {
    if (i <= mid) {
      for (int j = 0; j < 2 * i + 1; j++) {
        printf("*");
      }
      printf("\n");
    } else {
      for (int j = 0; j < 2 * (n - i) - 1; j++) {
        printf("*");
      }

      printf("\n");
    }
  }
}