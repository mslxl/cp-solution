#include <cstdio>
typedef unsigned long long ull;

int main(int argc, char *argv[]) {
    ull n;
    scanf("%lld", &n);
    if ( n > 4 )
        printf("%lld", n*(n-1)/2*(n-2)/3*(n-3)/4);
    else
        printf("0");
    return 0;
}
