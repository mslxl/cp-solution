#include<bits/stdc++.h>
// Çø -> Ê¡ -> ÊĞ

int N, M;

std::unordered_map<std::string, std::string> fa;
std::unordered_map<std::string, int> num;
std::unordered_map<std::string, std::string> loc;

bool is_all_digit(std::string & str){
    for(auto &ch: str){
        if(!std::isdigit(ch)){
            return false;
        }
    }
    return true;
}

void inc(const std::string &block){
    num[block]++;
    if(fa.count(block)){
        inc(fa[block]);
    }
}
void dec(const std::string& block){
    num[block]--;
    if(fa.count(block)){
        dec(fa[block]);
    }
}


int main(){
    std::cin >> N >> M;
    for(int i = 0; i < M; i++){
        std::string f,s;
        std::cin >> f >> s;
        if(is_all_digit(f)){
            loc[f] = s;
        }else{
            fa[f] = s;
        }
    }

    for(auto p : loc){
        inc(p.second);
    }
    std::string op;
    while(std::cin >> op && op != "E"){
        if(op == "Q"){
            std::string target;
            std::cin >> target;
            std::cout << num[target] << std::endl;
        }else if(op == "T"){
            std::string name, target;
            std::cin >> name >> target;
            dec(loc[name]);
            inc(target);
            loc[name] = target;
        }
    }


    return 0;
}
