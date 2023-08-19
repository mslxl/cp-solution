#include<cstdio>
#include<cstring>
const int oo=1000000007;
int f[5][45],c[10005][5],cnt[15],t,n;
char s[10005];
int main()
    {
    c[0][0]=1;
    for (int i=1;i<=10000;i++){
        c[i][0]=1;
        for (int j=1;j<5;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%oo;
    }
    scanf("%d",&t);
    while (t--){
        scanf("%s",s); n=strlen(s); long long z,ans=0;
        memset(cnt,0,sizeof(cnt)); memset(f,0,sizeof(f));
        for (int i=0;i<n;i++) cnt[s[i]-48]++; f[0][0]=1;
        for (int i=0;i<=9;i++)
            for (int j=3;j>=0;j--)
                for (int k=0;k<=36;k++) if (z=f[j][k])
                 for (int m=1;j+m<5;m++)
                     f[j+m][k+i*m]=(z*c[cnt[i]][m]+f[j+m][k+i*m])%oo;
        for (int j=1;j<5;j++)
            for (int k=9;k<=36;k+=9) ans=(ans+f[j][k])%oo;
        printf("%lld\n",ans);
    }
    return 0;
}
