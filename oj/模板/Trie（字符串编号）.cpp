#include <cstring>
#include <string>

namespace trie {
const int max_depth = 1000 * 4;
const int max_char = 26 + 7;
int trie[max_depth][max_char], index_trie = 1, str_id = 0;
int end_trie[max_depth];
void clear() {
  index_trie = 1;
  str_id = 0;
  std::memset(trie, 0, sizeof(trie));
  std::memset(end_trie, 0, sizeof(end_trie));
}
int insert_with_id(const std::string &str) {
  int depth = 1;
  for (int i = 0; i < str.size(); i++) {
    int ch = str[i] - '0';
    if (trie[depth][ch] == 0) {
      index_trie++;
      trie[depth][ch] = index_trie;
    }
    depth = trie[depth][ch];
  }
  if (end_trie[depth] == 0) {
    str_id++;
    end_trie[depth] = str_id;
  }
  return end_trie[depth];
}
} // namespace trie
