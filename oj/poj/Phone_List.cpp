#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include<cassert>

using namespace std;

int trie[10000 * 40][10 + 7], index_trie = 1;
bool end_trie[10000 * 40];
bool insert_into_trie(const string &str) {
  int depth = 1;
  for (int i = 0; i < str.size(); i++) {
    assert(depth < 10000 * 400);
    int ch = str[i] - '0';
    if (trie[depth][ch] == 0) {
      // 未记录该子串的自负，记录
      index_trie++;
      trie[depth][ch] = index_trie;
    } else if (i == str.size() - 1) {
      return true; //已记录字符串的最后一个字符，即该串是其余串的子串
    }
    depth = trie[depth][ch];
    if (end_trie[depth]) //其他串是该串的前缀
      return true;
  }
  end_trie[depth] = true;
  return false;
}

void solve() {
  int N;
  cin >> N;
  memset(trie, 0, sizeof trie);
  memset(end_trie, false, sizeof end_trie);
  index_trie = 1;
  bool illegal = false;
  while(N--){
    string line;
    cin >> line;
    if(illegal) continue;
    if(insert_into_trie(line)){
      illegal = true;
    }
  }
  if(illegal) {
    cout << "NO\n";
  }else{
    cout << "YES\n";
  }
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}