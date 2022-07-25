#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a1,a2,a3,b1,b2,b3;
	cin>>a1>>a2>>a3>>b1>>b2>>b3;
	if(a1+a2+a3>b1+b2+b3){
		if(a1>b1) cout<<"both"<<endl;
		else if(a1==b1&&a2>b2) cout<<"both"<<endl;
		else if(a1==b1&&a2==b2&&a3>b3) cout<<"both"<<endl;
		else cout<<"count"<<endl;	
	}
	else if(a1>b1) cout<<"color"<<endl;
	else if(a1==b1&&a2>b2) cout<<"color"<<endl;
	else cout<<"none"<<endl;
	return 0;
}
