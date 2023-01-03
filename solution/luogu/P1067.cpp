#include <stdio.h>

// MMP 全是细节
int main() {
    int n, ratio, i, counter = 0;

    scanf("%i", &n);
    for (i = n; i > 0; i--) {
        scanf("%i", &ratio);
        if (ratio == 0) {
            continue;
        } else if (i == 1) {
            if (ratio == 1) {
                if (counter == 0) {
                    printf("x");
                } else {
                    printf("+x");
                }
            } else if (ratio == -1) {
                printf("-x");
            } else if (counter == 0) {
                printf("%ix", ratio);
            } else {
                printf("%+ix", ratio);
            }
        } else if (ratio == 1) {
            if (counter == 0) {
                printf("x^%i", i);
            } else {
                printf("+x^%i", i);
            }
        } else if (ratio == -1) {
            printf("-x^%i", i);
        } else if (counter == 0) {
            printf("%ix^%i", ratio, i);
        } else {
            printf("%+ix^%i", ratio, i);
        }
        counter++;
    }
    scanf("%i", &ratio);
    if (ratio == 0) {
        if (counter == 0) {
            printf("0\n");
        } else {
            printf("\n");
        }
    } else if (counter == 0) {
        printf("%i\n", ratio);
    } else {
        printf("%+i\n", ratio);
    }


    return 0;
}