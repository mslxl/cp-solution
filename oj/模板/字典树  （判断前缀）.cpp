#include <string>
using namespace std;

int trie[1000 * 40][10 + 7], index_trie = 1;
bool end_trie[1000 * 40];
bool insert_into_trie(const string &str) {
  int depth = 1;
  for (int i = 0; i < str.size(); i++) {
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
