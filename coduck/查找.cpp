#include<bits/stdc++.h>

const int maxn = 1e6 + 17;
int a[maxn];
int n, m;

int main(){
  std::cin >> n >> m;
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }
  for(int __i = 0; __i < m; __i++){
    int v;
    std::cin >> v;

    int L = 1, R = n;

    while(L < R){
      int mid = (L + R) / 2;
      if(a[mid] >= v){
        R = mid;
      }else{
        L = mid+1;
      }
    }
    if(a[R] != v){
      std::cout << -1;
    }else{
      std::cout << R;
    }
    std::cout << " ";

  }

}