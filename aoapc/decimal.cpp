#include <cstdio>
#include <cmath>
#include <string>
using std::string;
int main(int argc, char *argv[]) {
    int a,b,c;
    char format[20];
    while(scanf("%d%d%d",&a,&b,&c) && a != b && b != c && a != 0){
        double v = 1.0 * a / b;
        sprintf(format,"%%.%df", c);
        printf(format,v);
    }

    return 0;
}
