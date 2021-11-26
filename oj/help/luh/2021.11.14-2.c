#include <math.h>
#include <stdio.h>
int main() {
    int sum = 0, val;
    while ((val = getchar()) != '\n') {
        val -= '0';
        sum += pow(val, 3);
    }
    printf("%d", sum);
    return 0;
}