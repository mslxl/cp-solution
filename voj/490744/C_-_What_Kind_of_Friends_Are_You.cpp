#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;

void solve() {
  int ask, num_ans;

  int N;
  std::cin >> ask >> num_ans;
  std::cin >> N;
  std::unordered_map<std::string, std::string> friends;

  for (int i = 0; i < N; i++) {
    std::string name;
    std::cin >> name;
    friends[name]  = "";
  }

  for (int i = 0; i < num_ans; i++) {
    std::set<std::string> answered_name;
    int n;
    std::cin >> n;
    while (n--) {
      std::string name;
      std::cin >> name;
      friends[name] += "1";
      answered_name.insert(name);
    }

    for (const std::pair<std::string, std::string>& entry : friends) {
      if (!answered_name.count(entry.first)) {
        friends[entry.first] += "0";
      }
    }

  }

  std::unordered_map<std::string, std::string> dict;
  for (const std::pair<std::string, std::string>& entry : friends) {
    if(dict.count(entry.second)){
      dict[entry.second] = "Let's go to the library!!";
    }else{
      dict[entry.second] = entry.first;
    }
  }

  for(int i = 0; i < ask; i++){
    std::string ss;
    for(int j = 0 ; j < num_ans; j++){
      std::string v;
      std::cin >> v;
      ss+=v;
    }
    if(dict.count(ss)){
      std::cout <<  dict[ss] << std::endl;
    }else{
      std::cout << "Let's go to the library!!" << std::endl;
    }
  }
}

int main() {
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
