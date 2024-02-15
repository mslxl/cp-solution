// Problem: A. Rook
// Url: https://codeforces.com/contest/1907/problem/A
// Contest: Codeforces - Codeforces Round 913 (Div. 3)
// Memory: 256mb
// Time: 1000ms
// Checker: wcmp
#include<bits/stdc++.h>
void solve(){
  std::string ip;
  std::cin >> ip;
  for(int i = '1'; i <= '8'; i++){
    if(i != ip[1]){
      std::cout << ip[0] << (char)i << "\n";
    }
  }
  for(int i = 'a'; i <= 'h'; i++){
    if(i != ip[0]){
      std::cout << (char)i << ip[1] << '\n';
    }
  }
  
}
int main(){
  int n;
  std::cin >> n;
  while(n--) solve();
  return 0;
}