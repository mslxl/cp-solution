#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
const int N = 1e5;

int n,m,q;
vector<pii> vc[N + 5],vd[N + 5];
int huan[N + 5];
int disc[N + 5],disd[N + 5];
bool note[N + 5];
multiset<int> ms;

void init(){
    cin>>n>>m>>q;
    int u,v,c,d;
    while(m--){
        cin>>u>>v>>c>>d;
        vc[u].push_back(pii(v,c));
        vd[v].push_back(pii(u,d));
    }
    for(int i = 1;i <= n;++i)
        cin>>huan[i];
    for(int i = 1;i <= n;++i)
        disc[i] = 1e18;
    for(int i = 1;i <= n;++i)
        disd[i] = 1e18;
    disc[1] = disd[n] = 0;
}

void dij1(){
    memset(note,0,sizeof(note));
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push(pii(0,1));
    while(!q.empty()){
        pii now = q.top();q.pop();
        if(note[now.second])
            continue;
        note[now.second] = true;
        for(int i = 0;i < vc[now.second].size();++i)
            disc[vc[now.second][i].first] = min(disc[vc[now.second][i].first],now.first + vc[now.second][i].second),
            q.push(pii(disc[vc[now.second][i].first],vc[now.second][i].first));
    }
}
void dij2(){
    memset(note,0,sizeof(note));
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push(pii(0,n));
    while(!q.empty()){
        pii now = q.top();q.pop();
        if(note[now.second])
            continue;
        note[now.second] = true;
        for(int i = 0;i < vd[now.second].size();++i)
            disd[vd[now.second][i].first] = min(disd[vd[now.second][i].first],now.first + vd[now.second][i].second),
            q.push(pii(disd[vd[now.second][i].first],vd[now.second][i].first));
    }
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    init();
    dij1();
    dij2();
    for(int i = 1;i <= n;++i){
        if(disc[i] < 1e18 && disd[i] < 1e18)
            ms.insert(disc[i] + (disd[i] + huan[i] - 1) / huan[i]);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(disc[a] < 1e18 && disd[a] < 1e18)
            ms.erase(ms.lower_bound(disc[a] + (disd[a] + huan[a] - 1) / huan[a]));
        huan[a] = b;
        if(disc[a] < 1e18 && disd[a] < 1e18)
            ms.insert(disc[a] + (disd[a] + huan[a] - 1) / huan[a]);
        cout<<*ms.begin()<<"\n";
    }
    return 0;
}