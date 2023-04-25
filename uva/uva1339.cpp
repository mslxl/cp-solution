#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <iterator>
int main(int argc, char *argv[]) {
    std::string str1, str2;
    int cs1[26],cs2[26];
    while(std::cin >> str1 >> str2){
        memset(cs1,0,sizeof(cs1));
        memset(cs2,0,sizeof(cs2));
        for (auto s:str1) {
            cs1[s-'A']++;
        }
        for (auto s:str2) {
            cs2[s-'A']++;
        }

        std::sort(std::begin(cs1),std::end(cs1));
        std::sort(std::begin(cs2),std::end(cs2));
        for (int i = 0; i < 26; i++) {
            if(cs1[i] != cs2[i]){
                printf("NO\n");
                goto outer;
            }
        }
        printf("YES\n");
    outer:
        str1 = "";
        str2 = "";
    }
    return 0;
}
