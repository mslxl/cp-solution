#include<iostream>
#include<algorithm>
#include<string>
const int maxn = 1e5 + 17;
#define int long long
std::string a[maxn];
int n;
int F[20][10];

int head(std::string &s){
	return s[0] - '0';
}

int last(std::string &s){
	return s[s.size()-1] - '0';
}

signed main(){
	std::cin >> n;
	for(int i = 1l; i <= n; i++){
		std::cin >> a[i];
	}
	F[1][last(a[1])] = 1;
	
	for(int i = 2; i <= n; i++){
		for(int l = 0; l <= 9; l++){
			F[i % 10][l] = F[(i-1) %10][l];
		}
		F[i % 10][last(a[i])] = F[(i-1) % 10][head(a[i])] + 1;
	}
	int max = 0;
	for(int l = 0; l <= 9; l++){
		max = std::max(F[n % 10][l], max);
	}
	std::cout << n - max;
	return 0;
}
