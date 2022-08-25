#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>

//#include"debug.h"
const int max_depth = 17 * 250000+17;
int trie[max_depth][26 + 7], index_trie = 1, str_id = 0;
int end_trie[max_depth];

int insert_with_id(const std::string &str) {
  int depth = 1;
  for (int i = 0; i < str.size(); i++) {
    int ch = str[i] - 'a';
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

const int maxn = 2500000 + 17;
int disjoint[maxn];
int rank[maxn];

void disjoint_init() {
  for (int i = 0; i < maxn; i++) {
    disjoint[i] = i;
  }
}

int disjoint_find_root(int u) {
  while (disjoint[u] != u) {
    u = disjoint[u];
  }
  return u;
}

void disjoint_joint(int x, int y) {
  x = disjoint_find_root(x);
  y = disjoint_find_root(y);
  if (x == y)
    return;
  if (rank[x] > rank[y]) {
    disjoint[y] = x;
  } else if (rank[y] > rank[x]) {
    disjoint[x] = y;
  } else {
    disjoint[x] = y;
    rank[y]++;
  }
}
int degree[2500000+17];
int main() {
  disjoint_init();
  std::ios::sync_with_stdio(false);
  std::cout.tie(0);
  std::cin.tie(0);

  std::string left, right;
  while (std::cin >> left >> right) {
    int lid = insert_with_id(left);
    int rid = insert_with_id(right);
    // debug(left,lid,right,rid);
    degree[lid]++;
    degree[rid]++;
    disjoint_joint(lid, rid);
  }
  int even_degree_number = 0;
  bool connected = true;
  const int root = disjoint_find_root(1);
  for (int i = 1; i <= str_id; i++) {
    if (degree[i] % 2 != 0) {
      even_degree_number++;
    }
    if (disjoint_find_root(i) != root) {
      connected = false;
      break;
    }
  }

  if ((even_degree_number == 0 || even_degree_number == 2) && connected) {
    std::cout << "Possible";
  } else {
    std::cout << "Impossible";
  }

  return 0;
}