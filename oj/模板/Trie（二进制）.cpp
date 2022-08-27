namespace trie {
const int max_depth = 30;
int trie[max_depth][2], total_depth = 0;
void insert(int num) {
  constexpr int max_bit_len = 30;
  int depth = 0;
  for (int i = max_bit_len; i >= 0; i--) {
    bool b = num & (1 << i);
    if (trie[depth][b] == 0) {
      total_depth++;
      trie[depth][b] = total_depth;
    }
    depth = trie[depth][b];
  }
}
int find(int num) {
  int depth = 0, result = 0;
  for (int i = 30; i >= 0; i--) {
    bool k = num & (1 << i);

    if (trie[depth][k ^ 1]) {
      result |= 1 << i;
      depth = trie[depth][k ^ 1];
    } else {
      depth = trie[depth][k];
    }
  }
  return result;
}
}; // namespace trie
