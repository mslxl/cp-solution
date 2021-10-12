#include <cstdio>
#include <cmath>
int main(int argc, char *argv[]) {
    int m,t,s;
    scanf("%d %d %d", &m, &t, &s);
    int avai;
    if (t == 0) {
        avai = 0;
    } else {
        int eaten = ceil(1.0 * s / t);
        if (eaten >= m){
            avai = 0;
        } else{
            avai = m - eaten;
        }
    }
    printf("%d", avai);
    return 0;
}
