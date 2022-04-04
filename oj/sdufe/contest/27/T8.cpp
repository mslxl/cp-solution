// 提倡二胎？

#include<bits/stdc++.h>
#ifdef Lo
#define test if(1)
#else
#define test if(0)
#endif

typedef unsigned long  long ll;
const ll modd = 1e9+7;
const ll maxn = 1e5 + 17;
const ll maxk = 10 + 17;

ll N,K;

// 0 -> small
// 1 -> big
ll single_st[20][2];
ll comp_st[maxn][2];

void build_st(){
  std::memset(single_st, 0 , sizeof(single_st));
  std::memset(comp_st, 0 , sizeof(comp_st));
  single_st[0][0] = 1;
  single_st[0][1] = 0;

  for (int i = 1; i < K; i++) {
    for (int j = 0; j < 2; j++) {
      single_st[i][1] = single_st[i-1][0] + single_st[i-1][1];
      single_st[i][0] = single_st[i-1][1];
    }
    test {
      std::cout << "The " << i << " year have " << single_st[i][0] 
        << " small, " <<single_st[i][1] << " big" << std::endl;
    }
  }

  for(int i = 1; i <= N; i++){
  ll cur_big_will_die = i / K;
    

  }






}


int main(){
  std::cin >> N >> K;
  build_st();

  return 0;
}
