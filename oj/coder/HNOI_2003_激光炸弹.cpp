#include<bits/stdc++.h>
int n,R;
struct Loc{
    int x,y,v;
};
int main(){
    std::cin >> n >> R;
    std::vector<Loc> map(n);
    for(int i = 0; i < n; i++){
        std::cin >> map[i].x >> map[i].y >> map[i].v;
    }


}