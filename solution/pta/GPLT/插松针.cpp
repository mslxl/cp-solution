#include<bits/stdc++.h>
const int maxn = 1e3 + 17;
int N, M, K;
std::queue<int> pusher;
std::stack<int> box;
std::vector<std::stack<int>> result;
std::stack<int> bunch;

#define debug if(0)

void output( std::stack<int> & st){
    if(st.empty()) return;
    if(st.size() == 1) {
        std::cout << st.top();
        return;
    }
    int t = st.top();
    st.pop();
    output(st);
    std::cout << " " << t;
}

int main(){
    std::cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        int v;
        std::cin >> v;
        pusher.push(v);
    }

    while(!box.empty() || !pusher.empty()){
        if(!box.empty() && bunch.size() < K && (bunch.empty() || box.top() <= bunch.top())){
            bunch.push(box.top());
            debug std::cout << "bunch +" << box.top() << "from box" << std::endl;
            box.pop();
            continue;
        }
        if(!pusher.empty() && bunch.size() < K){
            if(bunch.empty() || pusher.front() <= bunch.top()){
                bunch.push(pusher.front());
                debug std::cout << "bunch + " << pusher.front() << "from pusher" << std::endl;
                pusher.pop();
                continue;
            }else if(box.size() < M){
                box.push(pusher.front());
                debug std::cout << "box + " << pusher.front() << "from pusher" << std::endl;
                pusher.pop();
                continue;
            }
        }
        if(box.size() == M && (pusher.empty() || pusher.front() > bunch.top())){
            // 小盒子已经满了，但推送器上取到的松针仍然不满足要求
            result.push_back(bunch);
            bunch = std::stack<int>();
            debug std::cout << "produce bunch" << std::endl;
            continue;
        }
        if(pusher.empty() && (box.empty() || box.top() > bunch.top())){
            // 小盒子中最上面的松针不满足要求，但推送器上已经没有松针了
            result.push_back(bunch);
            bunch = std::stack<int>();
            debug std::cout << "produce bunch" << std::endl;
            continue;
        }
        if(bunch.size() == K){
            // 手中的松枝干上已经插满了松针
            result.push_back(bunch);
            bunch = std::stack<int>();
            debug std::cout << "produce bunch" << std::endl;
            continue;
        }

    }
    result.push_back(bunch);
    for( auto&i: result){
        output(i);
        std::cout << "\n";
    }

    return 0;
}
