#include<bits/stdc++.h>


struct tt{
  std::string name;
  int h;
  bool operator<(const tt&rhs) const {
    if(h == rhs.h){
      return name < rhs.name;
    }else{
      return h > rhs.h;
    }
  }
};

std::vector<tt> seq;

void solve(){
    std::string name;
    int c,t;
    std::cin >> name >> c >> t;
    int hard = c * 10 + t;
    seq.emplace_back(tt{
      name,
      hard
    });
}
int main(){
  int T;
  std::cin >> T;
  while(T--){
    solve();
  }
  std::sort(seq.begin(), seq.end());
  for(auto i: seq){
    std::cout << i.name  << " " << i.h << std::endl;
  }
  return 0;
}