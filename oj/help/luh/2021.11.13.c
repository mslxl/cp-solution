#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (x)>(y)? (x): (y)

int Commonmultiple(int i, int j) {
    int t;
    if (i != j) {
        for (t = max(i,j) ;t <= (i * j); t++) {
            if (t % i == 0 && t % j == 0) {
                return t;
            }
        }
    }else{
        return i;
    }
}
int main() {
    int x, y, i, j, a, b, re;
    int s, h;
    scanf("%d%d", &s, &h);
    re = Commonmultiple(s, h);
    printf("%d \n", re);
}