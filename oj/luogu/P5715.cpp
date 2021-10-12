#include <cstdio>
#include <algorithm>
int main(int argc, char *argv[]) {
    int num[3];
    scanf("%d%d%d",&num[0],&num[1],&num[2]);
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            if(num[i] > num[j]){
                std::swap(num[i],num[j]);
            }
        }
    }
    printf("%d %d %d", num[0], num[1], num[2]);
    return 0;
}
