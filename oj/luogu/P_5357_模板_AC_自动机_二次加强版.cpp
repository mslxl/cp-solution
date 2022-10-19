#include <cassert>
#include <climits>
#include <cstdint>
#include <set>
#include <queue>
#include <string>

int appear_times[2 * 100000 + 17];

namespace ojlib {
struct LowcaseAlphabetMapper {
  int operator()(const char &ch) { return ch - 'a'; }
};

template <std::size_t BranchNumber = 26,
          typename Mapper = LowcaseAlphabetMapper>
struct ACFA {
  Mapper mapper;
  struct Node {
    Node *fail = nullptr;
#ifdef _MSC_VER
    Node *ch[BranchNumber];
#else
    Node *ch[BranchNumber] = {nullptr};
#endif
    int count = 0;
    std::set<int> kds;
    unsigned int lastUpdateOnQueryCount = 0; //防止重复统计用

#ifdef _MSC_VER
    // fuck you MSVC
    Node() {
      for (int i = 0; i < BranchNumber; i++) {
        ch[i] = nullptr;
      }
    }
#endif
  };
  bool available = false;

  Node *superRoot, *root;

  unsigned int queryCount = 1;

  ACFA() { clear(); }

  void insert(const std::string &str, int tag) {
    available = false;
    Node *t = root;
    for (int i = 0; i < str.size(); i++) {
      int x = mapper(str[i]);
      if (t->ch[x] == nullptr)
        t->ch[x] = new Node;
      t = t->ch[x];
    }
    t->count++;
    t->kds.insert(tag);
  }
  // didn't recycle mem
  void clear() {
    root = new Node;
    superRoot = new Node;
    root->fail = superRoot;
    available = false;
    for (std::size_t i = 0; i < BranchNumber; i++)
      superRoot->ch[i] = root;
    superRoot->count = -1;
    superRoot->lastUpdateOnQueryCount = INT_MAX;
  }

  void freeNode(Node *node) {
    if (node == nullptr)
      return;
    for (std::size_t i = 0; i < BranchNumber; i++) {
      if (node->ch[i] != nullptr) {
        freeNode(node);
      }
      delete node;
    }
  }
  void build() {
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      Node *t = q.front();
      q.pop();
      for (std::size_t i = 0; i < BranchNumber; i++) {
        if (t->ch[i] != nullptr) {
          t->ch[i]->fail = t->fail->ch[i];
          for(auto)

          q.push(t->ch[i]);
        } else {
          t->ch[i] = t->fail->ch[i];
        }
      }
    }

    available = true;
  }

  int count(const std::string &str) {
    queryCount++;
    assert(available);
    int ans = 0;
    Node *t = root;
    for (std::size_t i = 0; i < str.size(); i++) {
      int x = mapper(str[i]);
      t = t->ch[x];
      for (Node *u = t; u->lastUpdateOnQueryCount < queryCount; u = u->fail) {
        ans += u->count;
        for (const auto &i : u->kds) {
          appear_times[i]++;
        }
        u->lastUpdateOnQueryCount = queryCount;
      }
    }
    return ans;
  }
};
} // namespace ojlib

#include <iostream>
int N;
ojlib::ACFA<26, ojlib::LowcaseAlphabetMapper> ac;

int main() {
  ac.clear();
  std::cin >> N;
  for (std::size_t i = 0; i < N; i++) {
    std::string l;
    std::cin >> l;
    ac.insert(l, i);
  }
  ac.build();
  std::string str;
  std::cin >> str;
  std::cerr << ac.count(str);
  for (int i = 0; i < N; i++) {
    std::cout << appear_times[i] << "\n";
  }
  return 0;
}