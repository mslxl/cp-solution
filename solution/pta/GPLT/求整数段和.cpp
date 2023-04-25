#include<bits/stdc++.h>
int main(){
    int begin, end;
    int sum = 0;
    std::cin >> begin >> end;
    int i = 0;
    for(; (begin + i) <= end; i++){
        printf("%5-d", begin + i);
        if((i+1) % 5 == 0) printf("\n");
        sum += (begin + i);
    }
    if(i % 5 != 0) 
        printf("\n");
    printf("Sum = %d", sum);
}