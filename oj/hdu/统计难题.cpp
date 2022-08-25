#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int trie[400000 ][26 + 7], index_trie = 1;
int tms_trie[400000];
bool insert_into_trie(const string &str) {
  int depth = 1;
  for (int i = 0; i < str.size(); i++) {
    int ch = str[i] - 'a';
    if (trie[depth][ch] == 0) {
      index_trie++;
      trie[depth][ch] = index_trie;
    }
    depth = trie[depth][ch];
    tms_trie[depth]++;
  }
  return false;
}

int find_end(const string &str) {
  int depth = 1;
  for (int i = 0; i < str.size(); i++) {
    int ch = str[i] - 'a';
    if (trie[depth][ch] != 0) {
      depth = trie[depth][ch];
    } else {
      return 0;
    }
  }
  return depth;
}

void solve() {
  memset(trie, 0, sizeof trie);
  memset(tms_trie, 0, sizeof tms_trie);
  index_trie = 1;

  string line;
  while (getline(cin, line)) {
    if(line.empty()) break;
    insert_into_trie(line);
  }
  while(getline(cin, line)){
    cout << tms_trie[find_end(line)] << "\n";
  }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}