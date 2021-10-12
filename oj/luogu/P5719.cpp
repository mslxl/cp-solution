#include <cstdio>
typedef unsigned long long ull;
int main(int argc, char *argv[]) {
    int n,k;
    double num1=0, num2=0;
    ull sum1 = 0, sum2 = 0;
    scanf("%d %d", &n ,&k);
    for (int i = 1; i <= n; i++) {
        if(i % k == 0){
            num1++;
            sum1 += i;
        }else{
            num2++;
            sum2 += i;
        }
    }
    printf("%.1f %.1f", sum1 / num1, sum2 / num2);
    return 0;
}
