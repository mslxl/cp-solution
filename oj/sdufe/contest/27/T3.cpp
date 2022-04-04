#include<bits/stdc++.h>
#ifdef Lo
#define test if(1)
#else
#define test if(0)
#endif
const int maxn = 100000 + 17;

typedef long long ll;

int st[maxn][maxn];
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> seq(n+1);
  for(int i = 1; i<= n;i++){
    std::cin >> seq[i];
  }

  std::vector<int> prefix(seq);

  for(int i = 1; i <= n; i++){
    prefix[i] = prefix[i] + prefix[i-1];
  }
  


  int q;
  std::cin >> q;

  for(int i = 0; i < q; i++){
    int op,x,y;
    std::cin >> op >> x >> y;
    if(op == 1){
      // normal prefix sum
      std::cout << (prefix[y] - prefix[x-1]) << std::endl;
    }else{
      std::cout << st[x][y - x + 1] << std::endl;
    }
  }



  return 0;
}
