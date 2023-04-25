#include<bits/stdc++.h>
#define rep(i,s,e) for(int i = s; i < e; i++)

void abbr(const std::string& word){
    const static std::string vowels = "aeiouy";
    rep(i, 0 ,word.size()){
        if(i == 0 || vowels.find(word[i]) == std::string::npos){
            std::cout << word[i];
        }
    }
    std::cout << std::endl;
}

int main(){
    int T;
    std::cin >> T;
    std::string line;
    while(T--){
        std::cin >> line;
        abbr(line);
    }
    return 0;
}