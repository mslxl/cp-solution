#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define int long long
const int N = 2e6 + 10;
string s1, s2;
int f[N][26];
bool d[N][26];
bool st[26];
int n, m;

signed main()
{
	cin >> s1 >> s2;
	n = s1.size(), m = s2.size();
	s1 = "?" + s1, s2 = "?" + s2;
	
	for(int i = 1 ; i <= m ; i ++ ) 
	{
		for(int j = 0 ; j < 26 ; j ++ )
			if(st[j]) d[j][s2[i] - 'a'] = true;
		st[s2[i] - 'a'] = true;
	}
	
	for(int i = 1 ; i <= n ; i ++ ) f[i][s1[i] - 'a'] = 1;
	for(int i = 1 ; i <= n ; i ++ )
	{
		if(!st[s1[i] - 'a'])
		{
			for(int j = 0 ; j < 26 ; j ++ ) 
				f[i][j] = f[i - 1][j] + 1;
		}
		else
		{
			for(int j = 0 ; j < 26 ; j ++ )
			{
				f[i][j] = max(f[i][j], f[i - 1][j]);
				if(!d[j][s1[i] - 'a'])
					f[i][s1[i] - 'a'] = max(f[i][s1[i] - 'a'], f[i - 1][j] + 1);
			}
		}
	}
	
	int res = 0;
	for(int i = 0; i < 26; i ++ )
		res = max(res, f[n][i]);
	cout << res << endl;
}
