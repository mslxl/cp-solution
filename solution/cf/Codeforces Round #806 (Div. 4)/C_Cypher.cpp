#include <bits/stdc++.h>
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> lock(n);
  for (int i = 0; i < n; i++)
    std::cin >> lock[i];
  for (int i = 0; i < n; i++) {
    int num_op;
    std::string op;
    std::cin >> num_op >> op;
    for(const auto c : op){
        if(c=='D'){
            lock[i]++;
        }else{
            lock[i]--;
        }
        if(lock[i]==-1){
            lock[i] = 9;
        }else if(lock[i] == 10){
            lock[i] = 0;
        }
    }
  }
    for(auto i: lock){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}