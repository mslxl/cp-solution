#include <cstdio>
int main(int argc, char *argv[]) {
    int a,b,c;
    while(scanf("%d %d %d", &a, &b, &c)){
        bool found = false;
        for (int i = 10; i <= 100; i++) {
            if((i - a) % 3 == 0 && (i - b) % 5 == 0 && (i - c) % 7 == 0){
                printf("%d", i);
                found = true;
                break;
            }
        }
        if (!found) {
            printf("No answer");
        }
    }
    return 0;
}
