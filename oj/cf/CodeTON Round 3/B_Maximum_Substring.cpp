#include<bits/stdc++.h>
using ll = long long;

void solve(){
  int n;
  std::cin >> n;
  std::string line;
  std::getline(std::cin, line);
  std::getline(std::cin, line);

  ll x = 0, y = 0;
  for(const auto& ch: line){
    x+= ch == '1';
    y+= ch == '0';
  }
  ll xy = x*y;

  ll last_elem_rep = 1;
  ll square = 0;
  for(int i = 1; i < line.size(); i++){
    if(line[i] == line[i-1]){
      last_elem_rep++;
      square = std::max(square, last_elem_rep * last_elem_rep);
    }else{
      last_elem_rep = 1;
    }
  }

  std::cout << std::max(last_elem_rep*last_elem_rep, std::max(square, xy)) << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;
  while(T--){
    solve();
  }
  return 0;
}