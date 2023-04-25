#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

std:: priority_queue<std:: pair<int ,int>,std:: vector<std:: pair<int,int> >,std:: greater<std:: pair<int,int> > >q;

const int maxn = 1e4+11;
int a[maxn];
struct tree_data{
	int maxx;
	int minn;
}tree[maxn<<2];

void update(int now){
	tree[now].maxx=std:: max(tree[now<<1].maxx,tree[now<<1|1].maxx);
	tree[now].minn=std:: min(tree[now<<1].minn,tree[now<<1|1].minn);
}

void build(int now,int l,int r){
	if(l==r){
		tree[now].maxx=a[l];
		tree[now].minn=a[r];
		return; 
	}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	update(now);
}

int quary_min(int now,int l,int r,int q_l,int q_r){
	int minn=210000000; 
	if(l==r){
		return tree[now].minn;
	}
	int mid=(l+r)>>1;
	if(mid>=q_r) minn=std:: min(minn,quary_min(now<<1,l,mid,q_l,q_r));
	if(mid<q_l) minn=std:: min(minn,quary_min(now<<1|1,mid+1,r,q_l,q_r));
	return minn;
}

int quary_max(int now,int l,int r,int q_l,int q_r){
	int maxx=-210000000; 
	if(l==r){
		return tree[now].maxx;
	}
	int mid=(l+r)>>1;
	if(mid>=q_r) maxx=std:: max(maxx,quary_max(now<<1,l,mid,q_l,q_r));
	if(mid<q_l) maxx=std:: max(maxx,quary_max(now<<1|1,mid+1,r,q_l,q_r));
	return maxx;
}
int main(){
	int n=read();
	a[1]=read();
	for(int i=2;i<=n;i++){
		a[i]=read();
		q.push(std:: make_pair(a[i]-a[i-1],i-1));
	}
	int ans_1=0;
	ans_1=quary_max(1,1,n,1,n)-quary_min(1,1,n,1,n);
	build(1,1,n);
	std:: cout<<ans_1<<std:: endl;
	for(int i=1;i<n;i++){
		if(q.top().first<=0){
			q.pop();
			std:: cout<<ans_1<<std:: endl;
			continue;
		}
		
	}
}
