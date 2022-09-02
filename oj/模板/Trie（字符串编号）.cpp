#include <array>
#include <cstring>
#include <string>


namespace ojlib {
struct LowcaseStringMap {
  int operator()(const char &c) { return c - 'a'; }
};
template <std::size_t Size = 1000 * 4, int CharRange = 26 + 7,
          typename Mapper = LowcaseStringMap>
struct TrieStringCounter {
  std::size_t str_id = 0;
  int trie[Size][CharRange];
  int end_trie[Size];
  int index_trie = 1;

  void clear() {
    index_trie = 1;
    str_id = 0;
    std::memset(trie, 0, sizeof(trie));
    std::memset(end_trie, 0, sizeof(end_trie));
  }

  int count(const std::string &str) {
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
};
} // namespace ojlib
