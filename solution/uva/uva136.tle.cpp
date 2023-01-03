#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using std::string;
typedef long long ll;
typedef unsigned long long ull;
std::priority_queue<ull, std::vector<ull>, std::greater<ull> > queue;

std::vector<ull> prime_cache;

bool is_prime(ull nul) {
    for (ull i = 2; i * i <= nul; i++) {
        if (nul % i == 0)
            return false;
    }
    return true;
}

bool is_ugly(ull num) {
    if (prime_cache.back() < num / 2) {
        for (ull cur = prime_cache.back() + 1; prime_cache.back() < num / 2;
             cur++) {
            if (is_prime(cur)) {
                prime_cache.push_back(cur);
            }
        }
    }
    if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
        for (auto item : prime_cache) {
            if (num % item == 0){
                return false;
            }
        }
        return true;
    }
    return false;
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    prime_cache.push_back(7);
    ull found_num = 0;
    ull target = -1;
    for(ull i = 5; found_num < 1500; i++){
        if(is_ugly(i)){
            found_num ++;
            std::cout << found_num << "\t:"<< i << std::endl;
            if(found_num == 1500){
                target = i;
            }
        }
    }
    std::cout << target;

    

    return 0;
}