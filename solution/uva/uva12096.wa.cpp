#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
typedef long long ll;
typedef unsigned long long ull;

ull test_case_num;
ull cmd_num;

std::stack<int> stack;
std::vector<std::vector<int>> items;
void _push(){
    std::vector<int> i;
    items.push_back(i);
    stack.push(items.size() - 1);
}
void _dup(){
    std::vector<int> i(items[stack.top()]);
    items.push_back(i);
    stack.push(items.size() - 1);
}
void _union(){
    std::vector<int> &t1 = items[stack.top()]; stack.pop();
    std::vector<int> &t2 = items[stack.top()]; stack.pop();
    std::set<int> un;
    for (auto i : t1)
        un.insert(i);
    for (auto i : t2)
        un.insert(i);
    std::vector<int> ret(un.begin(), un.end());
    items.push_back(ret);
    stack.push(items.size() - 1);
}
void _intersection(){
    std::vector<int> &t1 = items[stack.top()]; stack.pop();
    std::vector<int> &t2 = items[stack.top()]; stack.pop();
    std::set<int> un;
    for (auto i : t1){
        for(auto j: t2){
            if(i == j){
                un.insert(i);
            }
        }
    }
    std::vector<int> ret(un.begin(), un.end());
    items.push_back(ret);
    stack.push(items.size() - 1);
}
void _add(){
    int first_pop_id = stack.top();
    std::vector<int> &t1 = items[first_pop_id]; stack.pop();
    std::vector<int> &t2 = items[stack.top()]; 
    t2.push_back(first_pop_id);
}

int visit_set(int start_id){
    int num = 0;
    std::vector<int> &set = items[start_id];
    if(set.empty()){
        return 1;
    } else {
        for(auto item : set){
            num+= visit_set(item);
        }
        return num;
    }
}

void _print_top_num(){
    int top_id = stack.top();
    std::cout << visit_set(top_id) << std::endl;
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    std::string cmd;
    std::cin >> test_case_num;
    while (std::cin >> cmd_num)
    {
        for (ll i = 0; i < cmd_num; i++)
        {
            std::cin >> cmd;
            if(cmd[0] == 'A')
                _add();
            else if(cmd[0] == 'P')
                _push();
            else if(cmd[0] == 'I')
                _intersection();
            else if(cmd[0] == 'U')
                _union();
            else if(cmd[0] == 'D')
                _dup();
            _print_top_num();
        }
    }
    return 0;
}