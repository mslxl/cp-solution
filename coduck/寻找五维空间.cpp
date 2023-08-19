#include<bits/stdc++.h>
using namespace std;
int i,j,l,s,zi,mu,ll,t,qianj,n,m;
int LL,RR;
double now,an;
int gcd(int a,int b)
{
    if (a<b) return(gcd(b,a));
    if (b==0) return a;
    return(gcd(a %b,b));
}
void cheak(int u,int d)
{
    if ((u==n)&&(d==m)) return;
    if (gcd(u,d)!=1) return;
    if(u==d)return;
    double ss=double(u)/double(d);
    if (fabs(ss-now)<an)
    {
        an=fabs(ss-now);
        zi=u;
        mu=d;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d",&RR);
    an=99999999;
    now=double(n)/double(m);
    for (int i=2;i<=RR;i++)
    {
    int l=1;
    int r=i-1;
    while (l<r)
        {
            int mid=(l+r+1)/2;
            double ss=double(mid)/double(i);
            if (ss<now)l=mid;
            else r=mid-1;
        }
        cheak(l,i);
        cheak(l+1,i);
    }
    printf("%d %d\n",zi,mu);
    return 0;
}