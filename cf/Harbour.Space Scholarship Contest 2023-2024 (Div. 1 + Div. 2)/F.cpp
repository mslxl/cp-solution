#include<iostream>
#include<cstring>
#include<vector>
#include<numeric>
#include<functional>
using namespace std;
using LL = long long;

template<typename T>
struct Fenwick{
    int n;
    vector<T> tr;

    Fenwick(int n) : n(n), tr(n + 1, 0){}

    int lowbit(int x){
        return x & -x;
    }

    void modify(int x, T c){
        for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }

    void modify(int l, int r, T c){
        modify(l, c);
        if (r + 1 <= n) modify(r + 1, -c);
    }

    T query(int x){
        T res = T();
        for(int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }

    T query(int l, int r){
        return query(r) - query(l - 1);
    }

    int find_first(T sum){
        int ans = 0; T val = 0;
        for(int i = __lg(n); i >= 0; i--){
            if ((ans | (1 << i)) <= n && val + tr[ans | (1 << i)] < sum){
                ans |= 1 << i;
                val += tr[ans | (1 << i)];
            }
        }
        return ans + 1;
    }

    int find_last(T sum){
        int ans = 0; T val = 0;
        for(int i = __lg(n); i >= 0; i--){
            if ((ans | (1 << i)) <= n && val + tr[ans | (1 << i)] <= sum){
                ans |= 1 << i;
                val += tr[ans | (1 << i)];
            }
        }
        return ans;
    }

};
using BIT = Fenwick<int>;

struct Info {
    int mx = 0;
};

Info operator+(const Info &a, const Info &b){
    return {max(a.mx, b.mx)};
}

template<class Info>
struct SegmentTree{
    int n;
    vector<Info> info;

    SegmentTree() {}

    SegmentTree(int n, Info _init = Info()){
        init(vector<Info>(n, _init));
    }

    SegmentTree(const vector<Info> &_init){
        init(_init);
    }

    void init(const vector<Info> &_init){
        n = (int)_init.size();
        info.assign((n << 2) + 1, Info());
        function<void(int, int, int)> build = [&](int p, int l, int r){
            if (l == r){
                info[p] = _init[l - 1];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m + 1, r);
            pull(p);
        };
        build(1, 1, n);
    }

    void pull(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void modify(int p, int l, int r, int x, const Info &v){
        if (l == r){
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x <= m){
            modify(2 * p, l, m, x, v);
        } 
        else{
            modify(2 * p + 1, m + 1, r, x, v);
        }
        pull(p);
    }

    void modify(int p, const Info &v){
        modify(1, 1, n, p, v);
    }

    Info query(int p, int l, int r, int x, int y){
        if (l > y || r < x){
            return Info();
        }
        if (l >= x && r <= y){
            return info[p];
        }
        int m = (l + r) / 2;
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m + 1, r, x, y);
    }

    Info query(int l, int r){
        return query(1, 1, n, l, r);
    }
};

int main(){

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > pos(n + 1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    vector<vector<pair<int, int> > > query(n + 1);
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        query[r].push_back({l, i});
    }
    vector<int> ans(m);
    BIT bit(n);
    SegmentTree<Info> seg(n);
    vector<int> cnt(n + 1);
    for(int i = 1; i <= n; i++){  
        cnt[i] = cnt[i - 1];
        if (!pos[i].empty()){
            cnt[i] += 1;
            seg.modify(pos[i][0], {i});
            for(int j = 1; j < pos[i].size(); j++){
                int L = pos[i][j - 1] + 1, R = pos[i][j] - 1;
                if (L <= R){
                    bit.modify(1, seg.query(L, R).mx, 1);
                }
                seg.modify(pos[i][j], {i});
            }
        }
        for(auto [l, id] : query[i]){
            ans[id] = cnt[i] - cnt[l - 1] + bit.query(l);
        }
    }

    for(auto x : ans) cout << x << '\n';

}