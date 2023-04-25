#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 3000
#endif

int _runtimeTerror_()
{
    int n, Q;
    cin >> n >> Q;
    map<int, int> odd, even;
    vector<int> last_nz(n + 1, 0), last(n + 1, -1), pxor(n + 1, 0);
    vector<int> a(n + 1);
    even[0] = 0;
    int cur = 0;
    for(int i=1;i<=n;++i) {
    	cin >> a[i];
    	cur ^= a[i];
    	pxor[i] = cur;
    	if(a[i] == 0) {
    		last_nz[i] = last_nz[i - 1]; //前面上次不为0的在哪里 e.g. last not zero
    	}
    	else {
    		last_nz[i] = i;
    	}

    	if(i & 1) { //当前 i 为奇数
    		if(even.count(cur)) { // 这个 cur 在 i 为偶数时出现过了
    			last[i] = even[cur]; // 保存上次在偶数次出现和这次 cur 相同 xor 前缀的位置
    		}
    		odd[cur] = i; // 于 i 处 xor 前缀为 cur
    	}
    	else {
    		if(odd.count(cur)) {
    			last[i] = odd[cur];
    		}
    		even[cur] = i;
    	}
    }
    while(Q--) {
    	int l, r;
    	cin >> l >> r;
    	if(pxor[l - 1] != pxor[r]) { // 这一段区间的 xor 不为 0
    		cout << "-1\n";
    	}
    	else if(last_nz[r] < l) { // 全都是零
    		cout << "0\n";
    	}
    	else if(r % 2 == l % 2) { // r - l + 1 是奇数
    		cout << "1\n";
    	}
    	else if(a[l] == 0 or a[r] == 0) { // 虽然是偶数，但是左右有个0
    		cout << "1\n";
    	}
    	else if(last[r] >= l) { // 上次和 pxor[r] 相同的 xor 前缀位于 l 前（区间内）(即有后缀xor为0)
    		cout << "2\n";
    	}
    	else {
    		cout << "-1\n";
    	}
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initncr();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}	