#include<iostream>
#define ll long long
#include<bits/stdc++.h>

ll qz[1000006][3];
ll s[1000006];
ll h[1000006];
ll f[10];
int main(){
	ll n,q;
	ll x=0;
	std::string str;
	std::cin>>n>>q;
	std::cin>>str;
	str.push_back('0');
	if(str[0]=='1')qz[1][1]=1,x=1,h[1]=1;
	for(int i=1;i<=n;i++){
		ll j=i+1;
		if(str[i]=='1'){
			x++;
			if(x%2==0){
				qz[j][2]=qz[j-2][2]+1;
				qz[j][1]=qz[j-2][1];
			}
			else{
				qz[j][2]=qz[j-1][2];
				qz[j][1]=qz[j-1][1]+1;
			}
		}
		else{
			//std::cout<<x<<std::endl;
			for(int k=i-1;k>=i-x;k--){
				s[j-(i-k)]=(i-k);
				// std::cout<<j-(i-k)<<" "<<s[j-(i-k)]<<std::endl;
			}
			x=0;
			qz[j][2]=qz[j-1][2];
			qz[j][1]=qz[j-1][1];
		}
		h[j]=x;
		//std::cout<<qz[j][1]<<" "<<qz[j][2]<<std::endl;
		// std::cout<<s[i]<<" "<<h[i]<<std::endl;
		
	}
	// q++;
	while(q--){
		ll l,r;
		std::cin>>l>>r;
		f[2]=qz[r][2]-qz[l-1][2];
		f[1]=qz[r][1]-qz[l-1][1];
		// std::cout<<f[1]<<" "<<f[2]<<std::endl;
		// std::cout<<s[l]<<" "<<h[r]<<std::endl;
		if(s[l]>=(r-l+1)){
			std::cout<<"0"<<std::endl;
			continue;
		}
		if(h[l-1]%2==1&&s[l]%2==1){
			f[1]+=2;
			f[2]--;
		}
		// std::cout<<f[1]<<" "<<f[2]<<std::endl;
		if(h[r]%2==1&&s[l]%2==1){
			f[1]-=2;
			f[2]+=1;
		}
		ll ans=(r-(l-1))-3*(f[1]+f[2]);
		if(ans<0)ans=0;
		std::cout<<ans/3<<std::endl;
	}
}
