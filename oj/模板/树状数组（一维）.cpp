#include "debug.h"

#include<array>
#include<vector>
#include<iostream>

#define lowbit(x) ((-x)&x)
const int bit_size = 4000;
std::array<int, bit_size> bit;

void add(int i, int v){
    i++;
    for(; i <= bit_size; i += lowbit(i))
        bit[i] += v;
}

int prefix_sum(int i){
    i++;
    int s = 0;
    for(; i > 0; i -= lowbit(i))
        s += bit[i];
    return s;
}

int sum(int l, int r){
    return prefix_sum(r) - prefix_sum(l - 1);
}



int main(){
    int t;
    std::cin >> t;
    int num;
    for(int i = 0; i < t; i++) {
        std::cin >> num;
        add(i, num);
    }
    int q;
    std::cin >> q;
    for(int i = 0; i < q; i++){
        int l,r;
        std::cin >> l >> r;
        std::cout << sum(l,r) << std::endl;
    }

    return 0;
}