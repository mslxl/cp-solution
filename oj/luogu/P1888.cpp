#include<iostream>
#include<algorithm>
int main(){
    int l[3];
    std::cin >> l[0] >> l[1] >> l[2];
    std::sort(l,l+3);
    for(auto i = l[0]; i > 1; i--){
        if(l[0] % i == 0 && l[2] % i == 0){
            l[0] /= i;
            l[2] /= i;
        }
    }
    std::cout << l[0] << '/' << l[2];
}