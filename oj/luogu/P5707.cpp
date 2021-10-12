#include <cstdio>
#include <cmath>
int main(int argc, char *argv[]) {
    int s, v;
    scanf("%d %d",&s,&v);
    int need = ceil(1.0 * s / v) + 10;
    int times = 8 * 60;
    times -= need;
    if(times < 0){
        times += 24 * 60;
    }
    printf("%02d:%02d", times / 60, times % 60);

    return 0;
}
