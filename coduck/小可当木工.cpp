#include <algorithm>
#include<bits/stdc++.h>

void soviet();
int main(){
  soviet();

  return 0;
}

int n, m;
const int maxn = 1e5 + 17;
int x[maxn];

bool check(int mid){
  int cnt = 0;
  for(int i = 1; i <= n; i++){
    cnt += x[i] / mid;
  }
  return cnt >= m;
}

void soviet(){
  std::cin >> n >> m;
  for(int i = 1; i <= n; i++)
    std::cin >> x[i];
    

  int L = 0, R = *std::max_element(x+1, x+1+n);

  while(L < R){
    int mid = (L + R + 1)/2;
    if(check(mid)){
      L = mid;
    }else{
      R = mid - 1;
    }
  }
  std::cout << L;
}