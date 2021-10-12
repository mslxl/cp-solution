#include <cstdio>
int main(int argc, char *argv[]) {
    int x;
    scanf("%d", &x);
    bool c1 = x % 2 == 0;
    bool c2 = x > 4 && x <= 12;
    printf("%d %d %d %d", c1 && c2, c1 || c2, (c1 && !c2) || (!c1 && c2), !c1 && !c2);
    return 0;
}
