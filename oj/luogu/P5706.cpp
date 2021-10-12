#include<iostream>
#include<iomanip>
int main(){
    double t;
    int n;
    std::cin >> t >> n;

    std::cout << std::setprecision(3)<< std::fixed << t / n << std::endl << n * 2;
    return 0;
}