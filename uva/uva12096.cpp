#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <vector>
#include <map>
typedef long long ll;
typedef unsigned long long ull;

typedef std::set<int> Set;

std::stack<int> stack;
std::vector<Set> cache;
std::map<Set, int> id_cache;


ull test_case_num;
ull cmd_num;

void _print(){
    int top_id = stack.top();
    std::cout << cache[top_id].size() << std::endl;
}

int ID(const Set &set){
    if(id_cache.count(set)) return id_cache[set];
    cache.push_back(set);
    return id_cache[set] = cache.size() - 1;
}

void _push(){
    stack.push(ID(Set()));
}

void _dup(){
    Set set(cache[stack.top()]);
    stack.push(ID(set));
}

void _union(){
    Set set1 = cache[stack.top()]; stack.pop();
    Set set2 = cache[stack.top()]; stack.pop();
    Set un;
    for(auto i:set1)
        un.insert(i);
    for(auto i:set2)
        un.insert(i);
    stack.push(ID(un));
}

void _inter(){
    Set set1 = cache[stack.top()]; stack.pop();
    Set set2 = cache[stack.top()]; stack.pop();
    Set un;
    for(auto i:set1){
        for(auto j:set2){
            if(i == j){
                un.insert(i);
            }
        }
    }
    stack.push(ID(un));
}

void _add(){
    Set set1 = cache[stack.top()]; stack.pop();
    Set set2 = cache[stack.top()]; stack.pop();
    set2.insert(ID(set1));
    stack.push(ID(set2));
}

int main(int argc, char const *argv[]){
    std::ios::sync_with_stdio(false);
    
    std::string cmd;
    std::cin >> test_case_num;
    std::map<char,void (*)()> mp;
    mp['A'] = &_add;
    mp['P'] = &_push;
    mp['I'] = &_inter;
    mp['U'] = &_union;
    mp['D'] = &_dup;

    while (std::cin >> cmd_num)
    {
        for (ll i = 0; i < cmd_num; i++)
        {
            std::cin >> cmd;
            (*mp[cmd[0]])();
            _print();
        }
        std::cout << "***" << std::endl;
    }
    
    return 0;
}