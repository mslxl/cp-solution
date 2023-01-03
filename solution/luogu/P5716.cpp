#include <cstdio>
int main(int argc, char *argv[]) {
    const int b = 31, s = 30;
    int d[] = {b,0,b,s,b,s,b,b,s,b,s,b};
    int yyyy,mm;
    scanf("%d %d", &yyyy, &mm);
    printf("%d", d[mm - 1] != 0? d[mm - 1] :
           (((yyyy % 4 == 0 && yyyy % 100!= 0) || yyyy % 400 == 0)? 29 : 28));
    return 0;
}
