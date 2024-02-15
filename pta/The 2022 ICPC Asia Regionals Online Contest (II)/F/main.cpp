#include<bits/stdc++.h>
using namespace std;
#define ll long long
__int128 c[10015];
#define z 1e18
//节点每秒变成前一秒的k+1倍，所以先暂存一个k+1的幂数组 
inline void solve(ll k){
c[0]=1;
int i=1;
for( i=1;c[i-1]<=z;i++){
c[i]=c[i-1]*k; 
} 
}
inline void init(){
memset(c,0,sizeof(c));
}
int main(){
ll T;
ll k,x,y;
scanf("%lld",&T);
while(T--){
init();
scanf("%lld%lld%lld",&k,&x,&y);
stack<ll>a;
stack<ll>b;
//确保栈空（虽然可能没用） 
while(!a.empty())a.pop();
while(!b.empty())b.pop();
solve(k+1); 
ll a2=x,b2=y;
//把自身先入栈 
a.push(a2);b.push(b2);
//找x的所有父节点 
while(x!=1){
ll h=0;
for(ll i=0;i<=1000;i++){
//必须要找刚好小于的 
if(c[i]<x&&c[i+1]>=x){
h=i;break; 
}
}
ll m;
m=x-c[h];
if(m%k==0){
a.push(m/k);
x=m/k;
}
else {
a.push((m/k)+1);
x=m/k+1;
}
}
while(y!=1){
ll h=0;
for(ll i=0;i<=1000;i++){
if(c[i]<y&&c[i+1]>=y){
h=i;break; 
}
}
ll m;
m=y-c[h];
if(m%k==0){
b.push(m/k);
y=m/k;
}
else {
b.push((m/k)+1);
y=m/k+1;
}
}
// ll as=a.size(),bs=b.size();
int flag=1;
ll a1=0;
while(flag){
ll aa,bb;
// cout<<aa<<" "<<bb<<endl;
if(!a.empty()){
aa=a.top(),
a.pop();
}
if(!b.empty()){
bb=b.top();
b.pop();
}
if(aa==bb){
a1=aa;
}
if(aa!=bb||a.empty()||b.empty()){
// cout<<2<<endl;
cout<<a1;
flag=0;
break;
}
}
if(T!=0){
cout<<"\n";
}
} 
return 0;
}