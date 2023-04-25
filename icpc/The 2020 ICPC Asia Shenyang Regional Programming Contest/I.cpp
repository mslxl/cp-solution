#include<bits/stdc++.h>
using ll = long long;

int main(){
    ll H,M, A;
    std::cin >> H >> M >> A;
    if(A == H * M / 2){
        std::cout <<  H * M << "\n";
        return 0;
    }
    //std::cout << 2 * A + std::__gcd(H-1, H * M);
    std::cout << std::__gcd(H-1, H * M)*(2*(A/std::__gcd(H-1, H * M))+1);
    return 0;
}