#include <cstdio>
int main(int argc, char *argv[]) {
    unsigned long long num;
    scanf("%lld",&num);
    unsigned long long day = 1;
    if(num <= 1){
        printf("1");
        return 0;
    }
    for(; (num /= 2) != 1 ; day++);
    printf("%lld",day+1);

    return 0;
}
