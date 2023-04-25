#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

const int MAX_COLUMS = 60; // 一行最大的字符数

std::string get_max_len_str(std::string *start, std::string *end){
    std::string *max = nullptr;
    while(start != end){
        if(max == nullptr){
            max = start;
            continue;
        }
        if(max->size() < start->size()){
            max = start;
        }
        start++;
    }
    return *max;
}

std::string n_space(int n){
    std::string str(n,' ');
    return str;
}

int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    std::string * strs = new std::string[n];
    for (int i = 0; i < n; i++) {
        std::cin >> *(strs+i);
    }

    std::string max_len_str = get_max_len_str(strs, strs + n);
    int M = max_len_str.size();

    std::sort(strs, strs + n);
    int colums = (MAX_COLUMS - 2) / M - 1; // 列数
    int lines_in_percolums = (n / colums); // 一列有多少行
    int remins_item = n % colums; // 最后剩余的不构成一行

    for (int i = 0; i < MAX_COLUMS; i++) {
        std::cout << '-';
    }
    std::cout << '\n';


    for (int row = 0; row < lines_in_percolums; row++) {
        for(int col = 0; col < colums; col++){
            int pos = row + col * (lines_in_percolums + col > remins_item ? col: remins_item);
            std:: cout << *(strs + pos);
            int target_max = col == colums - 1 ? M + 2 : M;
            if((strs+pos)->size() < target_max){
                std::cout << n_space(target_max - (strs+pos)->size());
            }
        }
        std::cout << "\n";
    }
    // 输出多出的项
    for (int i = 0; i < remins_item;i++) {
        std::string *p = strs + ((lines_in_percolums + 1) * i) + lines_in_percolums;
        std::cout << *p;
        if(p->size() < M){
            std::cout << n_space(M - p->size());
        }
    }


    delete[] strs;
    return 0;
}
