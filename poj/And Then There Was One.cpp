// Problem: And Then There Was One
// Contest: Virtual Judge - POJ
// URL: https://vjudge.net/problem/POJ-3517
// Memory Limit: 64 MB
// Time Limit: 5000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// clang-format off
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 17;
int arr[maxn],cnt[maxn],f[maxn];
int main( )
{
    int N,M,K;
    while( scanf("%d%d%d",&N,&K,&M) != EOF )
    {
        if( !N )break;
        for( int i = 1; i <= N; i++ )
          arr[i] = i;
        while( M > N ) M -= N; arr[M] = -1; int k = 0;
        for( int i = 1; i <= N; i++ )
        if( arr[i] == -1 )
        {
            for( int j =i+1; j <= N; j++ )cnt[k++] = arr[j];
            i = N+1;
        }
        for( int i = 1; i <= N; i++ )
        if( arr[i] != -1 )cnt[k++] = arr[i];
        else break;
        f[0] = 0;
        for( int i = 1; i < k; i++ )f[i] = (f[i-1]+K)%(i+1);
        cout<<cnt[f[k-1]]<<endl;
    }
    return 0;
}