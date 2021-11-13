#include <stdio.h>
int main() {
    printf("Please type a number: ");
    int num;
    scanf("%d", &num);

    int is_prime = 1;

    for (int i = 2; i * i < num; i++) {
        if (num % i == 0) {
            is_prime = 0;
            break;
        }
    }

    if (is_prime) {
        printf("%d is prime", num);
    }else{
        printf("%d is not prime", num);
    }
    return 0;
}
