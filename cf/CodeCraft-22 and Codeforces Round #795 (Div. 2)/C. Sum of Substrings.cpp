#include<bits/stdc++.h>

char str[(std::size_t)1e5 + 17];

int calc(int n){
	int sum = 0;
	for(int i = 0; i+1 < n;i++){
		sum += (str[i]-'0') * 10 + (str[i+1] - '0');
	}
	return sum;
}

void solve(){
	std::memset(str, 0, sizeof(str));
	int n,k;
	scanf("%d%d", &n,&k);
	scanf("%s", str);
	if(k == 0){
		printf("%d\n", calc(n));
		return;
	}
	if(n >= 2&&str[n-1] == '0' && str[n-2] == '1'){
		std::swap(str[n-1], str[n-2]);
		k--;
	}
	for(int l = n - 2; l -1 > 0 && k > 0; l--){
		if(str[l-1] == '1' && str[l] == '0' && str[l + 1] == '0' ){
			std::swap(str[l-1], str[l]);
			k--;
		}else if( str[l - 1] == '1' &&str[l] == '1' && str[l + 1] == '0'){
			std::swap(str[l+1], str[l]);
			k--;
		}else if( str[l - 1] == '0' &&str[l] == '1' && str[l + 1] == '1'){
			std::swap(str[l-1], str[l]);
			k--;
		}
	}
	printf("%d\n", calc(n));
	return;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		solve();
	}
	return 0;
}
