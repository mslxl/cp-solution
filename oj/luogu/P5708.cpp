#include <cstdio>
#include <cmath>
int main(int argc, char *argv[]) {
    double a,b,c,p;
    scanf("%lf%lf%lf",&a,&b,&c);
    p = (a + b + c)/2;
    printf("%.1lf", sqrt(p * (p -a) * (p -b) * (p -c )));
    return 0;
}
