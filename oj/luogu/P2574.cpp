#include <cstdio>

#define ValueType int
#define RangeType int
struct SegTreeNode {
  SegTreeNode *ptr_left_node = nullptr, *ptr_right_node = nullptr;
  RangeType left, right;
  ValueType tag, value;
  constexpr RangeType mid() { return left + (right - left) / 2; }
  constexpr RangeType interval_size() { return this->right - this->left + 1; }
  SegTreeNode &left_node() {
    if (ptr_left_node == nullptr) {
      ptr_left_node = new SegTreeNode(left, mid());
    }
    return *ptr_left_node;
  }
  SegTreeNode &right_node() {
    if (ptr_right_node == nullptr) {
      ptr_right_node = new SegTreeNode(mid() + 1, right);
    }
    return *ptr_right_node;
  }
  SegTreeNode(RangeType l, RangeType r) : left(l), right(r) {}
  void pull_up() { this->value = left_node().value + right_node().value; }
  void push_down() {
    SegTreeNode &ln = left_node();
    SegTreeNode &rn = right_node();
    if (this->tag % 2 != 0) {
      ln.value = ln.interval_size() - ln.value;
      ln.tag += this->tag % 2;

      rn.value = rn.interval_size() - rn.value;
      rn.tag += this->tag % 2;
      this->tag = 0;
    }
  }
  ValueType ask(RangeType start, RangeType end) {
    if (right < start || end < left)
      return 0;
    if (start <= left && right <= end) {
      return this->value;
    } else {
      push_down();
      return left_node().ask(start, end) + right_node().ask(start, end);
    }
  }

  void damage(RangeType start, RangeType end) {
    if (right < start || end < left)
      return;
    if (start <= left && right <= end) {
      this->tag += 1;
      this->value = this->interval_size() - this->value;
    } else {
      push_down();
      left_node().damage(start, end);
      right_node().damage(start, end);
      this->pull_up();
    }
  }

  void build_from_stdio(RangeType start, RangeType end) {
    if (right < start || end < left)
      return;
    if (left == right && right <= end) {
      scanf("%1d", &this->value);
    } else if (start <= left && right <= end) {
      left_node().build_from_stdio(start, end);
      right_node().build_from_stdio(start, end);
      this->pull_up();
    }
  }
};

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  SegTreeNode seg(1, n);
  seg.build_from_stdio(1, n);
  int op, l, r;
  while (m--) {
    scanf("%d%d%d", &op, &l, &r);
    if (op == 0) {
      seg.damage(l, r);
    } else {
      printf("%d\n", seg.ask(l, r));
    }
  }
}
