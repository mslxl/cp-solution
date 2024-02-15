#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define endl '\n'
const int N = 1e6 + 10;
int n, m, s[N], pre[N], suf[N];
string str;

int calc(int l, int r)
{
    int ll = l + pre[l], rr = r - suf[r];
    if(ll >= rr) return (r - l + 1) >> 1;
    return s[rr] - s[ll - 1] + (pre[l] + suf[r] + 1) / 2;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    cin >> str;
    str = "?" + str;
    int last = -1;
    for(int i = 1; i <= n ; i ++ ) 
    {
        if(str[i] == '1')
        {
            if(last != i - 1) s[i] = 1, last = i;
            else last = -1;
        }
        s[i] += s[i - 1];
    }
    
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(str[i] == '1') suf[i] = suf[i - 1] + 1;
        else suf[i] = 0;
    }
    
    for(int i = n ; i >= 1 ; i -- ) 
    {
        if(str[i] == '1') pre[i] = pre[i + 1] + 1;
        else pre[i] = 0;
    }

    while (m -- )
    {
        int l, r;
        cin >> l >> r; 
        int t = calc(l, r);
        int len = (r - l + 1) / 3;
        cout << max(0, len - t) << endl;
    }
}