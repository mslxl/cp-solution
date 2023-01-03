#include <cmath>
#include <cstdio>

int main() {
  int t;
  int num_gd;
  char gd;
  scanf("%d", &t);
  while (t--) {
    int x = 0, y = 0;
    double far = 0;
    scanf("%d", &num_gd);
    scanf("%c", &gd);
    while (num_gd--) {
      scanf("%c", &gd);
      // printf("Receive: %c\n", gd);
      if (gd == 'L')
        x--;
      else if (gd == 'R')
        x++;
      else if (gd == 'U')
        y++;
      else if (gd == 'D')
        y--;
      far = fmax(far, sqrt(x * x + y * y));
    }
    printf("%.12lf\n", far);
  }
}
