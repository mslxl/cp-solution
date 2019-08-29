#include<iostream>
int main(){
    int N,i;
    std::cin>>N;
    for(int j = 0; j < N; j++){
        std::cin >> i;
        if(i % 2 == 0){
            std::cout << "zs ";
        }else{
            std::cout <<"pn ";
        }
        std::cout << "wins" << std::endl;
    }
}