#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>

using std:: endl;
using std:: cin;
using std:: cout;

typedef unsigned long long ull;
typedef long long ll;
int n,d;
const int maxn = 10001;

ll a[maxn];

ull deal(int l,int r){
	ull sum=0;
	
	for(int i = 2; i <= n; i++){
		ll left = a[i-1] < l? l : a[i-1];
		left = left > r? r : left;
		
		ll right = a[i] < l? l : a[i];
		right = right > r? r : right;
		
		sum += std::abs(left - right);
	}
	return sum;
	
//	for(int i=1;i<l;i++){
//		if(a[i]>r) a[i]=r;
//		if(a[i]<l) a[i]=l;
//	}
//	for(int i=r+1;i<=n;i++){
//		if(a[i]>r) a[i]=r;
//		if(a[i]<l) a[i]=l;
//	}
//	for(int i=2;i<=n;i++){
//		sum+=std:: abs(a[i]-a[i-1]);
//	}
//	return sum;
}
int main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	if(d>=n){
		ull ans=0;
		for(int i=2;i<=n;i++){
			ans+=std:: abs(a[i-1]-a[i]);
		}
		cout<<ans;
		return 0;
	}else{
		ull ans=0;
		for(int i=1;i<=n-d;i++){
			
			ans=std:: max(ans,deal(i,i+d));
//			std::cerr << "cmp " << ans << std::endl;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
