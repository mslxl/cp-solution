#include<bits/stdc++.h>
int main(){
    int n;
    std::cin >>n ;

    if(n >= 7){
        std::cout << "(4*5-3)+(6+1-7)*2";
        for(int i = 8; i <= n;i++){
            std::cout << "*" << i;
        }
    }else if(n == 6){
        std::cout << "(1+4)*3+2*(6-5)";
    }else if(n==5){
        std::cout << "3+4+2*5*1";
    }else if(n == 4){
        std::cout << "(1+4)*3+2";
    }else{
        std::cout << -1;
    }
    return 0;
}