#include<stdio.h>
int main(){
    int x,y,z =0, a,b,k=1;
    scanf("%d%d", &x,&y);
    while(x>0 && y >0){
        a = x % 2;
        x = x/2;
        b = y % 2;
        y = y/2;
        z = z + k * (a&b);
        k = k * 2;
    }
    printf("%d",z);
    return 0;
}