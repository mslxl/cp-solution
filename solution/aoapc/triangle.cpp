#include <cstdio>
void pr(int n,char c){
    for(int i = 0; i < n; i++){
        printf("%c", c);
    }
}
int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; n > 0; i++) {
        pr(i,' ');
        pr(n,'*');
        pr(i,' ');
        printf("\n");
        n-=2;
    }
    return 0;
}
