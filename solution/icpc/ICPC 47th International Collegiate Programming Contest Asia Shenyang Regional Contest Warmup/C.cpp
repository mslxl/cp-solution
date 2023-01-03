#include<iostream>
#include<algorithm>

const int maxn = 1e4+11;

int a[maxn];
int d[maxn];

int main(){
	std::ios:: sync_with_stdio(false);
	int n; std:: cin>>n>>a[1];
	int ans_2=0;
	int num=0;
	for(int i=2;i<=n;i++){
		std:: cin>>a[i];		
		d[i-1]=a[i]-a[i-1];
		if(d[i-1]>0){
			ans_2+=d[i-1];
		}else{
			num++;
		}
	}
	std:: cout<<ans_2<<std:: endl;
	std:: sort(d+1,d+n);
	int jf=0;
	for(int i=2;i<=n;i++){
		if(num>0){
			std:: cout<<ans_2<<std:: endl;
			continue;
		}
		jf+=d[num+i-1];
		std:: cout<<ans_2-jf<<std:: endl;
	}
	return 0;
	
}
