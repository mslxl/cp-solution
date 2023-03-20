#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<cstdlib>
#include<queue>
 
const int maxn = 2e5 + 17;
int cntx[maxn],cnty[maxn];
int ansx, ansy;
int main(){
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int x,y;
        std::cin >> x >> y;
        cntx[x]++;
        cnty[y]++;
        if(cntx[x] == 1){
            ansx+=2;
        }
        if(cntx[x-1] < cntx[x] && cntx[x] > cntx[x+1]){
            ansx+=2;
        }else if(cntx[x-1] >= cntx[x] && cntx[x] <= cntx[x+1]){
            ansx-=2;
        }
        if(cnty[y] == 1){
            ansy+=2;
        }
        if(cnty[y-1] < cnty[y] && cnty[y] > cnty[y+1]){
            ansy+=2;
        }else if(cnty[y-1] >= cnty[y] && cnty[y] <= cnty[y+1]){
            ansy-=2;
        }
        std::cout << ansx << " " << ansy << "\n";
    }
}
