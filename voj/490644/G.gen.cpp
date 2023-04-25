#include<bits/stdc++.h>
#define rep(i,s,e) for(int i = s; i < e; i++)
bool is_luck(int v){
    return v % 7 == 0 && v % 4 != 0;
}

int main(){
    rep(i, 0, 801){
        if(is_luck(i)){
            std::cout << "if(n<=" << i << "){\nstd::cout << " << i << " << std::endl;\n return;\n}" <<std::endl;
        }
    }    
}