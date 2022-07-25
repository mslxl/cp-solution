#include<iostream>
#include<cstdio>
#include <type_traits>


template<typename T>
std::enable_if<std::is_integral<T>::value> rd(T& v){
    char ch;
    int flag = 1;
    v = 0;
    while(!std::isdigit(ch = getchar())){
        if(ch == '-'){
            flag = -1;
        }
    }
    while(std::isdigit(ch = getchar())){
        v = v * 10 + ch - '0';
    }
}

template<typename T, typename ...A>
void rd(T& v, A& ...etc){
    rd(v);
    rd(etc...);
}

struct Node{

};



int main(){

    return 0;
}