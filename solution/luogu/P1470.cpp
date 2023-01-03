// [USACO2.3]最长前缀 Longest Prefix 
#include <algorithm>
#include<bits/stdc++.h>
#include <iosfwd>
#include <sstream>

std::vector<std::string> vec;
std::string line;

const int maxs = 2 * 1e5 + 17;
const int maxp = 200 + 17;
const int maxn = 76;
using ll = long long;
ll dp[maxs];

bool startWith(const std::string& wd, const std::string& c, int offset = 0){
  if(c.size() > wd.size()){
    return false;
  }
  for(int i = 0; i < c.size(); i++){
    if(wd[offset+i] != c[i]){
      return false;
    }
  }
  return true;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::fill(dp, dp + maxs, -1);

  while(std::cin >> line && line != "."){
    vec.push_back(line);
  }
  line = "";
  std::string wd;
  while(std::cin >> wd){
    line+=wd;
  }

  dp[0] = 0;

  for(int i = 0; i < line.size(); i++){
    for(int j  = 0; j < vec.size(); j++){
      if(dp[i] != -1 && startWith(line, vec[j], i)){
          dp[i+vec[j].size()] = std::max(dp[i+vec[j].size()], (long long)(dp[i] + vec[j].size()));
      }
    }
  }

  ll ans = 0;
  for(int i = 0; i <= line.size();i++){
    ans = std::max(ans, dp[i]);
  }
  std::cout << ans;
}