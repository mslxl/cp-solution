#include <cstdio>
#include <cmath>

bool is_daffodil(int num){
    int &ABC = num;
    int C = ABC % 10, B = ABC / 10 % 10, A = ABC / 100;
    return ABC == pow(C,3) + pow(B,3) + pow(A, 3);
}
int main(int argc, char *argv[]) {
    for(int i = 100; i <= 999; i++){
        if(is_daffodil(i))
            printf("%d ",i);
    }

    return 0;
}
