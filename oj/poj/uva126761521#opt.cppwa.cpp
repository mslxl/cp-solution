#include <algorithm>
#include<bits/stdc++.h>
#ifdef Lo
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;

struct Node{
  int len;
  bool is_leaf;
};

void solve(std::vector<ll>& data){
  std::sort(data.begin(), data.end(), std::greater<ll>());
  ll max = data[data.size() - 1];

  ll length = 0;
  ll last_encode = -1;
  ll last_lenght = 1;

  for(int i = 0; i < data.size(); i++){
    if(last_encode == -1 || data[i] != last_encode){
      length += last_lenght - 1 ? last_lenght - 1 : 1;
      test std::cout << "process " << data[i] << ", length ->" << length <<  " (+" << (last_lenght - 1 ? last_lenght - 1 : 1) <<  std::endl;
      last_lenght++;
    }else{
      assert(data[i] == last_encode);
      length += last_lenght - 1;
      test std::cout << "process " << data[i] << ", length ->" << length <<  " (+" << last_lenght - 1  <<  std::endl;
    }
    last_encode = data[i];
  }

  std::cout << length << std::endl;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  while(std::cin >> T){
    std::vector<ll> seq(T);
    for(int i = 0; i < T; i++){
      std::cin >> seq[i];
    }
    solve(seq);
  }

  return 0;
}
