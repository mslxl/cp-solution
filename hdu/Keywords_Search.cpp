#include <bits/stdc++.h>
#include <cassert>

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
    Node *ch[BranchNumber] = {nullptr};
    int count = 0;
  };
  bool available = false;

  Node *superRoot, *root;
  ACFA(){
    clear();
  }

  void insert(const std::string &str) {
    available = false;
    Node *t = root;
    for (int i = 0; i < str.size(); i++) {
      int x = mapper(str[i]);
      if (t->ch[x] == nullptr)
        t->ch[x] = new Node;
      t = t->ch[x];
    }
    t->count++;
  }
  // didn't recycle mem
  void clear() {
    root = new Node;
    superRoot = new Node;
    root->fail = superRoot;
    available = false;
    for(std::size_t i = 0; i < BranchNumber; i++)
        superRoot->ch[i] = root;
    superRoot->count = -1;
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
          q.push(t->ch[i]);
        } else {
          t->ch[i] = t->fail->ch[i];
        }
      }
    }

    available = true;
  }

  int count(const std::string &str) {
    assert(available);
    int ans = 0;
    Node *t = root;
    for (std::size_t i = 0; i < str.size(); i++) {
      int x = mapper(str[i]);
      t = t->ch[x];
      // 注释 for 以将 she 对 she,he 的匹配变为1(仅识别she)（需要保留 ans+=u->count;）
      for (Node *u = t; u->count != -1; u = u->fail) {
        ans += u->count;
        u->count = -1;
      }
    }
    return ans;
  }
};
} // namespace ojlib

int N;
ojlib::ACFA<26> ac;

void solve() {
    ac.clear();
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::string l;
    std::cin >> l;
    ac.insert(l);
  }
  ac.build();
  std::string str;
  std::cin >> str;
  std::cout << ac.count(str) << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--)
    solve();
}