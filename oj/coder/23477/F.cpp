#include <cstdio>
typedef unsigned long long ll;
ll n, q;
class Node {
public:
  Node *parent = nullptr;
  virtual ll value();
};

class Leaf : Node {
public:
  Leaf(ll *v) : v(v) {}
  ll *v;
  ll value() { return *v; }
};

class Op : Node {
public:
  char op;
  ll cache = -1;
  Node *left = nullptr, *right = nullptr;
  ll value() {
    if (cache != -1)
      return cache;
    if (op == '*') {
      cache = left->value() * right->value();
    } else if (op == '+') {
      cache = left->value() + right->value();
    }
    return cache;
  }
};
ll *nums;
int main() {
  scanf("%lld%lld", &n, &q);
  nums = new ll[n];
  Node *root = nullptr;
  char lastOp char op;
  for (int i = 0; i < n - 1; i++) {
  }

  return 0;
}
