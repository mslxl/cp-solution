#include <cstdio>
int main(int argc, char *argv[]) {
    int y;
    scanf("%d",&y);
    printf("%d", ((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0);
    return 0;
}
