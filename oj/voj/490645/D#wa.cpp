#include <bits/stdc++.h>


std::unordered_map<std::string, int> cache;

int dfs(std::string &s, std::vector<int> &v, int last_score){
  if(cache.count(s)){
    return cache[s];
  }

  int ans = last_score;
  for(int i = 0; i < s.size()-1; i ++){
    if(s[i]=='(' && s[i+1] == ')'){
      int new_score = last_score;
      std::string nl(s);
      std::vector<int> nv(v);

      std::swap(nl[i], nl[i+1]);
      std::swap(nv[i], nv[i+1]);
      new_score += v[i] * v[i+1];

      ans = std::max(std::max(new_score, dfs(nl,nv, new_score)), ans);
      cache[s] = ans;
    }
  }
  return ans;
}


void solve() {
  int n;
  std::cin >>n;
  std::cin.get();
  std::string l;
  std::getline(std::cin, l);
  std::vector<int> v(n);
  for(int i = 0; i < n; i++){
    std::cin >> v[i];
  }
  std::cout << dfs(l, v, 0) << std::endl;
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}