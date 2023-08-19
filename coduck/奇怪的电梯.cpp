#include<cstdio>
#include<iostream>
using namespace std;
int n,a,b,ans=0x7ffffff;
int to[205];
bool vis[205];
void dfs(int now,int sum)
{
    if(now==b) ans=min(ans,sum);
    if(sum>ans) return;
    vis[now]=1;
    
    if(now+to[now]<=n&&!vis[now+to[now]]) dfs(now+to[now],sum+1);
    if(now-to[now]>=1&&!vis[now-to[now]]) dfs(now-to[now],sum+1);
    vis[now]=0;
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++) scanf("%d",&to[i]);
    vis[a]=1;
    dfs(a,0);
    if(ans!=0x7ffffff) printf("%d",ans);
    else printf("-1");
    return 0;
}