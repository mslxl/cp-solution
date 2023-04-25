#include <cstdio>
#include <cstring>

typedef unsigned long long ull;
const int maxn = 100001;
ull n[maxn];
void gen_num(ull num){
    ull generator = num;
    ull ret = num;
    while(num > 0){
        ret += num % 10;
        num /= 10;
    }
    if(ret < maxn && n[ret] == 0){
        n[ret] = generator;
    }
}
int main(int argc, char *argv[]) {
    memset(n,0,sizeof(n));

    for(ull i = 1; i <= maxn; i++){
        gen_num(i);
    }

    for(ull i = 1; i <= maxn; i++){
        if(n[i] != 0){
            printf("%lld\tMin Generator: %lld \t\t|", i, n[i]);
        }
    }


    return 0;
}
