class Solution {
public:

    std::vector<bool> vis;
    std::vector<int> pri;
    void filter_prime(int upper){
        vis.resize(upper + 1);
        pri.reserve(upper + 1);
        vis[1] = true;
        for(int i = 2; i <= upper; i++){
            if(!vis[i]){
                pri.push_back(i);
            }
            for(auto p : pri){
                if(1LL * p * i > upper) break;
                vis[p * i] = true;
                if(i % p == 0) break;
            }
        }
    }
    std::vector<std::vector<int>> graph;


    std::vector<int> disjoint_fa;
    std::vector<int> depart_size;

    int find(int x){
        while(disjoint_fa[x] != x) x = disjoint_fa[x];
        return x;
    }

    void merge(int x, int y){
        if(x == y) return;
        x = find(x);
        y = find(y);
        disjoint_fa[x] = y;
    }


    long long cnt_deepin_till_pri(int x, int fa){
        long long cnt = 1;
        for(auto child: graph[x]){
            if(child == fa) continue;
            if(!vis[child]) continue;
            cnt += cnt_deepin_till_pri(child, x);
            merge(child, x);
        }
        return cnt;
    }

    long long solve_node(int rt){
        long long taken_node = 1;
        long long ans = 0;
        for(auto child: graph[rt]){
            if(!vis[child]) continue;
            long long cur_branch_cnt = depart_size[find(child)];
            if(cur_branch_cnt == 0)
                cur_branch_cnt = cnt_deepin_till_pri(child, rt);
            depart_size[find(child)] = cur_branch_cnt;
            ans += taken_node * cur_branch_cnt;
            taken_node += cur_branch_cnt;
        }
        return ans;
    }

    long long solve(){
        long long ans = 0;
        for(auto p: pri){
            ans += solve_node(p);
        }
        return ans;
    }

    long long countPaths(int n, vector<vector<int>>& edges) {
        filter_prime(n);
        disjoint_fa.resize(n+1);
        depart_size.resize(n+1);
        for(int i = 0; i <= n; i++) disjoint_fa[i] = i;
        graph.resize(n + 1);
        for(auto& e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        return solve();
    }
};
