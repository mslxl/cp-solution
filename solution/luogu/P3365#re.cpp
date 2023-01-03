#include<bits/stdc++.h>
#define rep(i,s,e) for(int i = s;i < e; i++)
#define fors(i,s,e) rep(i,s,e+1)
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
using ll = long long;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch< '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return f * x;
}
const int maxn  = 1e5  + 17;

int table[maxn][21];

// start from index 1 would be more convinent
void build_st(const std::vector<int>& data){
	fors(i, 1, data.size()){
		table[i][0] = data[i-1];
	}
	int k = std::log2(data.size());
	fors(j, 1, k){
		fors(i, 1, data.size() - (1 << j) + 1 + 1){
			table[i][j] = std::max(table[i][j-1], table[i + (1 << (j - 1))][j-1]);
		}
	}
}
int query_st(int left,int right){
	int k = std::log2(right - left + 1);
	return std::max(table[left][k], table[right-(1<<k)+1][k]);
}

int main(){
	
	int N, M;
	N = read(), M = read();
	std::vector<int> data(N);
	rep(i,0,N) data[i] = read();
	build_st(data);
	rep(_i, 0, M){
		int l = read(),r = read();
		printf("%d\n", query_st(l,r));
	}
	return 0;
}
