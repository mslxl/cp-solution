#include <cstdio>
#include <cmath>
#include <cstring>
int main(int argc, char *argv[]) {
    int n,k;
    scanf("%d%d", &n, &k);
    bool *lights = new bool[n];
    memset(lights,false,sizeof(bool) * n);

    for (int i = 1; i <= k; i++) {
        int pos = i - 1;
        for(; pos <= n; pos += i){
            auto l = (lights + pos);
            *l = ! *l;
        }
    }

    for (int i = 1; i <= n; i++) {
        if(*(lights + i - 1)){
            printf("%d", i);
            if(i != n) printf(" ");
        }
    }
    delete[] lights;
    return 0;
}
