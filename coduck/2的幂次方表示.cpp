#include<bits/stdc++.h>

std::map<int ,std::string> c;

std::string bin(int n){
  if(c.count(n)) return c[n];
  int key = n;
  std::string ans;
  for(int i = 0; n != 0; i++, n >>=1){
    if(n & 1){
      if(!ans.empty()){
        ans = "+" + ans;
      }
      if(i == 1){
        ans = "2" + ans;
      }else{
        ans = "2(" + bin(i) + ")" + ans;
      }
    }
  }
  if(ans.empty()) ans = "0";
  c[key] = ans;
  return ans;
}

int main(){
  int n;
  std::cin >> n;
  std::cout << bin(n);


  return 0;
}