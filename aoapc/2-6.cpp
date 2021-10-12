#include <cstdio>
#define min(x,y) (x)>(y)? (y) : (x)
#define max(x,y) (x)>(y)? (x) : (y)
int main(int argc, char *argv[]) {
    int n = 0;
    while(scanf("%d", &n)){
        if(n ==0)
            break;
        int *input = new int[n];
        for(int i = 0; i < n; i++){
            scanf("%d", input + i);
        }
        int min_v = 2147483647;
        int max_v = -2147483648;
        int sum = 0;
        int *start = input, *end = input + n;
        while(start != end){
            min_v = min(min_v, *start);
            max_v = max(max_v, *start);
            sum += *start;
            start++;
        }
        delete[] input;
        printf("%d %d %.3f", min_v, max_v, sum * 1.0 / n);
    }
    return 0;
}
