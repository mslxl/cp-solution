#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)

struct Node{
     double money;
     int count;
     int id;
} a[10005];

int cmp(const Node& A,const Node& B){
    if(A.money!=B.money){
        return A.money>B.money;
    }if(A.count!=B.count){
        return A.count>B.count;
    }if(A.id!=B.id){
        return A.id<B.id;
    }
}
int main(){
    int b,c;
    std::cin>>b;
    for(int i=0;i<=b;i++){
        a[i].count=0;
        a[i].id=i;
        a[i].money=0;
    }

    for(int i=1;i<=b;i++){
        std::cin>>c;
        int id;
        double sum=0,sumTwo=0;
        for(int j=1;j<=c;j++){
            std::cin>>id>>sum;
            a[id].id=id;
            a[id].money+=(sum/100.0);
            a[id].count++;
            sumTwo+=sum;
        }
        a[i].money-=sumTwo/100.0;
     }
    std::sort(a+1,a+b+1,cmp);
    for(int i=1;i<=b;i++){
        printf("%d %.2f\n",a[i].id,a[i].money);
    }
    return 0;
}
