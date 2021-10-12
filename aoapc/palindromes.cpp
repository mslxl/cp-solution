#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
std::string s;
char alphabet[] = "A...3..HIL.JM.O...2TUVWXY5",
    num[] = "01SE.Z..8.";

int main(int argc, char *argv[]) {
    std::cin >> s;
    bool is_pali;
    bool is_mirror;
    // isPhi
    {
        auto begin = s.begin(), last = s.end() - 1;
        while(last != begin && last - begin > 0){
            if(*begin != *last){
                is_pali = false;
                goto mirr;
            }
            begin++;
            last--;
        }
    }
    is_pali = true;

    mirr:
    // isMirr
    std::string m(s);
    for(auto &cc : m){
        if(isdigit(cc)){
            cc = num[cc - '0'];
        }else{
            cc = alphabet[cc - 'A'];
        }
    }
    reverse(m.begin(), m.end());
    is_mirror = m == s;
    printf("%s -- is ", s.c_str());

    if(!is_pali && !is_mirror) printf("not a palindrome");
    if(is_pali && !is_mirror) printf("a regular palindrome");
    if(!is_pali && is_mirror) printf("a mirrored string");
    if(is_pali && is_mirror) printf("a mirrored palindrome");
    return 0;
}
