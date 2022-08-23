//#include "../模板/debug.h"

#include<map>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

int hash_string(string str){
    int v = 0;
    for(string::const_iterator iter = str.begin(); iter != str.end();iter++){
        v *= 31;
        v += *(iter);
    }
    return v;
}

map<int, string> dict;

int main(){
    string wd;
    while(getline(cin, wd)){
        if (wd.empty()) break;
        stringstream ss;
        ss << wd;
        string key, value;
        
        ss >> value >> key;
        dict[hash_string(key)] = value;
    }

    while(cin >> wd){
        int id = hash_string(wd);
        if(dict.count(id)){
            std::cout << dict[id] << "\n";
        }else{
            std::cout << "eh\n";
        }
    }
    return 0;
}