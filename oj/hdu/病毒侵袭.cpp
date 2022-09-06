#include <cassert>
#include <climits>
#include <cstdint>
#include <iostream>
#include <queue>
#include <set>
#include <string>

namespace ojlib {
struct VirusMapper {
  int operator()(const char &ch) { return ch - 33; }
};
 struct ACFA {
    const static int BranchNumber = 126-33+1;
  VirusMapper mapper;
  struct Node {
    Node *fail = nullptr;
    Node *ch[BranchNumber];
    int tag = 0;
    unsigned int lastUpdateOnQueryCount = 0; //防止重复统计用
    Node(){
        for(int  i=0; i < BranchNumber; i++){
            ch[i] =nullptr;
        }
    }
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
    t->tag = tag;
  }
  // didn't recycle mem
  void clear() {
    root = new Node;
    superRoot = new Node;
    root->fail = superRoot;
    available = false;
    for (std::size_t i = 0; i < BranchNumber; i++)
      superRoot->ch[i] = root;
    superRoot->lastUpdateOnQueryCount = INT_MAX;
  }
  std::queue<Node *> q;
  void build() {
  
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

  std::set<int> count(const std::string &str) {
    std::set<int> virus;
    queryCount++;
    assert(available);
    Node *t = root;
    for (std::size_t i = 0; i < str.size(); i++) {
      int x = mapper(str[i]);
      t = t->ch[x];
      // 注释 for 以将 she 对 she,he 的匹配变为1(仅识别she)（需要保留
      // ans+=u->count;）
      for (Node *u = t; u->lastUpdateOnQueryCount < queryCount; u = u->fail) {
        if (u->tag != 0) {
          virus.insert(u->tag);
        }
        u->lastUpdateOnQueryCount = queryCount;
        if (virus.size() == 3) {
            return virus;
        }
      }
    }
    return virus;
  }
};
} // namespace ojlib

int n_virus;
int n_website;

ojlib::ACFA ac;
int main() {
  std::cin >> n_virus;
  for (int i = 1; i <= n_virus; i++) {
    std::string virus;
    std::cin >> virus;
    ac.insert(virus, i);
  }
  ac.build();

  std::cin >> n_website;
  int total = 0;
  for (int i = 1; i <= n_website; i++) {
    std::string url;
    std::cin >> url;
    auto v = ac.count(url);
    if (!v.empty()) {
      total++;
      std::cout << "web " << i << ":";
      for (auto &c : v) {
        std::cout << " " << c;
      }
      std::cout << "\n";
    }
  }
  std::cout << "total: " << total;
  return 0;
}