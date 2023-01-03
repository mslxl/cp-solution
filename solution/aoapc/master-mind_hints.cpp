#include <cstdio>
int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int *nums = new int[n];
    int *guess = new int[n];
    for (int i = 0; i < n && scanf("%d", nums + i); i++);


    bool exit = true;
    for (int i = 0; scanf("%d", guess + i); i++) {
        if(*(guess + i) != 0){
            exit = false;
        }
        if((i+1) % n == 0 && i != 0){
            if(exit) break;
            printf("Game %d", (i+1)/n);

        }
    }

    delete[] nums;
    delete[] guess;
    return 0;
}
