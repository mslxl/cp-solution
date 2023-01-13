#include<bits/stdc++.h>

const int INF = std::numeric_limits<int>::max();

using PII = std::pair<int, int>; // pair of <int,int>
using State = std::vector<std::pair<int, int>>;


const int epsilonEdge = 0;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCallsOfFunction"
class Nfa : public std::vector<State> {
    const std::string &pat;
    int cur = 0;

    /// 构建状态，并加入默认 epsilon 转换
    /// 加入队尾
    /// \return
    int createState() {
        int root = size();
        push_back(State());
        return root;
    }

    /// 构建原子公式
    /// \return 末状态
    PII parseAtom() {
        if (std::isdigit(pat[cur])) {
            int begin = createState();
            int end = createState();
            at(begin).emplace_back((int) pat[cur], end);
            cur++;
            return {begin, end};
        } else if (pat[cur] == '[') {
            cur++;
            int begin = createState();
            int end = createState();
            std::set<int> chs;
            while (cur < pat.length() && std::isdigit(pat[cur])) {
                chs.insert((int) pat[cur++]);
            }
            assert(pat[cur++] == ']'); // 输入错误, Expected token!
            for (int ch: chs) at(begin).emplace_back(ch, end);
            return {begin, end};
        } else {
            assert(pat[cur++] == '(');
            auto node = parseAlt(); // TODO
            assert(pat[cur++] == ')');
            return node;
        }
    }

    /// S-expand
    /// \return
    PII parseReg() {
        int begin = createState();
        int end = begin;
        auto peek2PlusOp = [&]() {
            while (cur < pat.length() && pat[cur] == '+') cur++;
        };
        while (cur < pat.length() && (std::isdigit(pat[cur]) || pat[cur] == '[' || pat[cur] == '(')) {
            auto next = parseAtom();
            if (cur < pat.length() && pat[cur] == '+') {
                peek2PlusOp();
                at(end).emplace_back(epsilonEdge, next.first);
                at(next.second).emplace_back(epsilonEdge, next.first);
                end = next.second;
            } else {
                at(end).emplace_back(epsilonEdge, next.first);
                end = next.second;
            }
        }
        return {begin, end};
    }

    /// Alter-combine
    /// \return
    PII parseAlt(){
        int begin = createState();
        auto next = parseReg();
        at(begin).emplace_back(epsilonEdge, next.first);
        std::vector<int> subEnd {next.second};
        while(cur < pat.length() && pat[cur] == '|'){
            cur++;
            auto next = parseReg();
            at(begin).emplace_back(epsilonEdge, next.first);
            subEnd.push_back(next.second);
        }
        int end = createState();
        for(auto& state: subEnd){
            at(state).emplace_back(epsilonEdge, end);
        }
        return {begin, end};
    }

public:
    explicit Nfa(const std::string& pat) : pat(pat){
        parseAlt();
    }
};
#pragma clang diagnostic pop

//inline decltype(auto) release(int u, int v){
//
//}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string pattern, str;
    std::cin >> pattern >> str;

    Nfa nfa{pattern};
    int nfaSize = nfa.size();
    int strSize = str.length();
    auto dis = std::vector<std::vector<int>>(nfaSize, std::vector<int>(strSize + 1, INF));
    std::deque<PII> deq;
    dis[0][0] = 0;
    deq.emplace_back(0,0);


    const auto m = str.length();
    while(!deq.empty()){
        auto cur = deq.front();
        int ddis = dis[cur.first][cur.second];
        deq.pop_front();

        auto releaseFront = [&](int u, int v){
            if(dis[u][v] > ddis ){
                dis[u][v] = ddis;
                deq.emplace_front(u, v);
            }
        };
        auto releaseBack = [&](int u, int v){
            if(dis[u][v] > ddis + 1){
                dis[u][v] = ddis + 1;
                deq.emplace_back(u, v);
            }
        };
        if(cur.second < m){
            releaseBack(cur.first, cur.second+ 1);
        }
        for(auto &[ch, next] : nfa[cur.first]){
            if(ch == epsilonEdge){
                releaseFront(next, cur.second);
            }else{
                // do matching operation
                if(cur.second < m){
                    if(ch == str[cur.second]){
                        releaseFront(next, cur.second + 1);
                    }if(m) {
                        // fail
                        // panic mode for back
                        releaseBack(next, cur.second + 1);
                    }
                }
            }
            // fail
            // insert operation
            releaseBack(next, cur.second);
        }
    }
    std::cout << dis[nfaSize - 1][m];


    return 0;
}
