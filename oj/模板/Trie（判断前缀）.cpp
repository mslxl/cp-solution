#include <array>
#include <string>


namespace ojlib {

struct NumberStringMap {
  int operator()(const char &c) { return c - '0'; }
};

template <std::size_t Size = 40000, int CharRange = 10,
          typename Mapper = NumberStringMap>
struct TriePrefixJudge {
  std::array<std::array<int, CharRange>, Size> trie;
  bool word_end[Size];
  int total = 1;

  bool insert(const std::string &str) {
    int depth = 1;
    for (int i = 0; i < str.size(); i++) {
      int ch = str[i] - '0';
      if (trie[depth][ch] == 0) {
        // 未记录该子串的字符，记录
        total++;
        trie[depth][ch] = total;
      } else if (i == str.size() - 1) {
        return true; //已记录字符串的最后一个字符，即该串是其余串的子串
      }
      depth = trie[depth][ch];
      if (word_end[depth]) //其他串是该串的前缀
        return true;
    }
    word_end[depth] = true;
    return false;
  }
};

} // namespace ojlib
