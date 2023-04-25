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
            // С�����Ѿ����ˣ�����������ȡ����������Ȼ������Ҫ��
            result.push_back(bunch);
            bunch = std::stack<int>();
            debug std::cout << "produce bunch" << std::endl;
            continue;
        }
        if(pusher.empty() && (box.empty() || box.top() > bunch.top())){
            // С����������������벻����Ҫ�󣬵����������Ѿ�û��������
            result.push_back(bunch);
            bunch = std::stack<int>();
            debug std::cout << "produce bunch" << std::endl;
            continue;
        }
        if(bunch.size() == K){
            // ���е���֦�����Ѿ�����������
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
