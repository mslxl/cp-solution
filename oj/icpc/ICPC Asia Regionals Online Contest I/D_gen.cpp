#include<iostream>
#include<cstdio>
using ll = unsigned long long;
const ll maxn = 1e9;

int ctz(ll num){
	int ret = 0;
	while((num & 1) == 0){
		ret++;
		num >>= 1;
	}
	return ret;
}

int popcount(ll x){
	int ret = 0;
	while(x != 0){
		if(x & 1){
			ret ++;
		}
		x >>= 1;
	}
	return ret;
}

bool is_good_number(ll num){
	return ctz(num) == popcount(num);
}


int main(){
	FILE *f = fopen("D_table.cpp", "w");
	fprintf(f, "int table[]={");
	bool fst = true;
	for(ll i = 1; i < maxn; i++){
		if(is_good_number(i)){
			if(!fst){
				fprintf(f, ",%lld", i);
			}else{
				fst = false;
				fprintf(f, "%lld", i);
			}
		}
	}
	fprintf(f, "};");
	fflush(f);
	fclose(f);
	return 0;
	
}
