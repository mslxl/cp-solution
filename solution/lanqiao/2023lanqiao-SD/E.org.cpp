#include<iostream>
#include<algorithm>
#include<string>
const int maxn = 1e5 + 17;
std::string a[maxn];
int n;
int F[maxn][10];

int head(std::string &s){
	return s[0] - '0';
}

int last(std::string &s){
	return s[s.size()-1] - '0';
}

int main(){
	std::cin >> n;
	for(int i = 1l; i <= n; i++){
		std::cin >> a[i];
	}
	F[1][last(a[1])] = 1;
	
	for(int i = 2; i <= n; i++){
		for(int l = 0; l <= 9; l++){
			F[i][l] = F[i-1][l];
		}
		F[i][last(a[i])] = F[i-1][head(a[i])] + 1;
	}
	int max = 0;
	for(int l = 0; l <= 9; l++){
		max = std::max(F[n][l], max);
		
	}
	std::cout << n - max;
}
