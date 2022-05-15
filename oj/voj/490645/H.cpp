include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int maxn=100010;

int n;
int head[maxn],tot;
struct edge{
    int v,nxt;
}e[maxn*2];
void init(){
    tot=0;
    for(int i=0;i<=n;i++) head[i]=-1;
}
void addedge(int u,int v){
    e[tot].v=v;e[tot].nxt=head[u];
    head[u]=tot++;
}
int dp[maxn];
void dfs(int u,int p){
    dp[u]=0;
    for(int i=head[u];~i;i=e[i].nxt){
        int v=e[i].v;
        if(v==p) continue;
        dfs(v,u);
        dp[u]+=dp[v];
    }
    if(dp[u]==0) dp[u]=1;
    else dp[u]--;
}
int main(){
    scanf("%d",&n);
    int u,v;
    init();
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs(1,1);
    if(dp[1]==0) puts("Bob");
    else puts("Alice");
    return 0;
}