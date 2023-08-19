#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=5e5+100;
struct nod{
    int to;
    int ne;
}e[maxn];
int head[maxn];
int n,k,d;
int b[maxn];
bool vis[maxn];
int qq[maxn],step[maxn]; 
int cnt;
void add(int u,int v){
    e[cnt].to=v;
    e[cnt].ne=head[u];
    head[u]=cnt++;
}
struct node{
    int s;
    int d;
};
void BFS(int x){
    queue<node>q;
    q.push({x,0});
    while(!q.empty()){
        node p=q.front();
        q.pop();
        int u=p.s;
        int dis=p.d;
        for(int i=head[u];~i;i=e[i].ne){
            int v=e[i].to;
            if(dis+1<=d&&qq[v]>(dis+1)){
                vis[v]=true;
                qq[v]=min(qq[v],dis+1);
                q.push({v,dis+1});
            }
        }
    }
}
int main(){
    memset(head,-1,sizeof(head));
    
    scanf("%d%d%d",&n,&k,&d);
//    for(int i=0 ;i<n*2+20 ;i++) head[i] = -1;
    for(int i=1;i<=n;i++){
        qq[i]=0x3f3f3f3f;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&b[i]);
        vis[b[i]]=1;
    }
    int x,y;
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=k;i++){
        BFS(b[i]); 
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans++;
        }
    }
    printf("%d",ans);
    
}
