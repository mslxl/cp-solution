#include<iostream>
#include<algorithm>

bool isP(const std::string &s){
  int l = 0, r = s.size() - 1;
  while(l < r){
    if(s[l] != s[r]){
      return false;
    }
    l++;
    r--;
  }
  return true;
}

int main(){
  std::string wd;
  std::cin >> wd;
  std::string rwd = wd;
  std::reverse(rwd.begin(), rwd.end());
  std::string minP = wd + rwd;
  for(int i = 0; i < rwd.size(); i++){
    std::string sub = rwd.substr(rwd.size() - i,i);
    std::string n = wd + sub;
    if(isP(n) && n.size() < minP.size()){
      minP = n;
    }
  }
  std::cout << minP;
  return 0;
}