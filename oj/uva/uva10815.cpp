#include<iostream>
#include<sstream>
#include<set>
#include<cctype>

std::set<std::string> arr;

void del_non_alpha(std::string &s){
    for(auto &c:s){
        if(!isalpha(c)){
            c=' ';
        } else if(isupper(c)){
            c=tolower(c);
        }
    }
}


int main(int argc, char const *argv[])
{   
    std::string str, buf;
    while(std::cin >> str){
        del_non_alpha(str);
        std::stringstream ss(str);
        while(ss >> buf) arr.insert(buf);
    }

    for(auto c : arr){
        std::cout << c << std::endl;
    }

    return 0;
}
