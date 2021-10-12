#include <cstdio>
int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int local = n * 5;
    int remote = n * 3 + 11;
    printf("%s", local > remote? "Luogu":"Local") ;
    return 0;
}
