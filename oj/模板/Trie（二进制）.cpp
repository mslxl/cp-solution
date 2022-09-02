#include <array>

namespace oblib {
template <std::size_t ItemLen = 31, std::size_t ItemNum = 100000>
struct TrieBin {
  int total_depth = 0;
  std::array<std::array<int, 2>, ItemLen * ItemNum> trie;

  void insert(int num) {
    int depth = 0;
    for (int i = ItemLen; i >= 0; i--) {
      bool b = num & (1 << i);
      if (trie[depth][b] == 0) {
        trie[depth][b] = ++total_depth;
      }
      depth = trie[depth][b];
    }
  }
  
  int find(int num) {
    int depth = 0, result = 0;
    for (int i = ItemLen; i >= 0; i--) {
      bool b = num & (1 << i);

      if (trie[depth][b ^ 1]) {
        result += 1 << i;
        depth = trie[depth][b ^ 1];
      } else {
        depth = trie[depth][b];
      }
    }
    return result;
  }
};
} // namespace oblib
