#include <cstdio>
#include <cmath>
int main(int argc, char *argv[]) {
    double n,m;
    while(scanf("%lf%lf",&n,&m) && n != m){
        double value = 0;
        for(; n <= m; n++){
            value += 1 / pow(n,2);
        }
        printf("%.5f", value);
    }
    return 0;
}
