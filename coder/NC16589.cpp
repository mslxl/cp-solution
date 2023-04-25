#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int M, N , value, times = 0;
    std::cin >> M >> N;
    std::vector<int> dict;
    while (std::cin >> value) {
        if (std::find(dict.begin(), dict.end(), value) == dict.end()) {
            dict.push_back(value);
            times++;
        }
        if (dict.size() > M){
            dict.erase(dict.begin());
        }
    }
    printf("%d",times);
}