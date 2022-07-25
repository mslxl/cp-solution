#include<bits/stdc++.h>

//int bob[] = {2,3,17,19};
int bob[] = {5,7,11,13};
const int max = 1e5;

std::set<int> result;


void dfs(int cur_coin){
  if(cur_coin > max){
    return;
  }
  for(int i = 0; i < 4; i++){
    int t = cur_coin + bob[i];
    if(!result.count(t)){
      result.insert(t);
      // printf("%d ", t);
      dfs(t);
    }
  }
}

int main(){
  dfs(0);
  for(int i = 1; i < max; i++){
    if(!result.count(i)){
      printf("%d ", i);
    }
  }
}