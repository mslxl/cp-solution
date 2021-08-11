#include<iostream>
int main(){
    char c;
    std::cin >> c;
    c+='A'-'a';
    std::cout << c;
    return 0;
}