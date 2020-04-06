#include<iostream>
#include<iomanip>
int main(){
    int m,n,k;
    std::cin >> n >> m >> k;
    bool * map = new bool[n*n];
    std::memset(map,false,sizeof(bool) * n * n);
    return 0;
}