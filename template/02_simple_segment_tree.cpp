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
  void pull_up() {
    // TODO
    this->value = left_node().value + right_node().value;
  }
  void push_down() {
    SegTreeNode &ln = left_node();
    SegTreeNode &rn = right_node();
    // TODO
    ln.value = this->tag * ln.interval_size();
    ln.tag = this->tag;

    rn.value = this->tag * rn.interval_size();
    rn.tag = this->tag;
  }
  ValueType ask(RangeType start, RangeType end) {
    if (right < start || end < left)
      // TODO
      return 0;
    if (start <= left && right <= end) {
      // TODO
      return this->value;
    } else {
      push_down();
      // TODO
      return left_node().ask(start, end) + right_node().ask(start, end);
    }
  }

  void update(RangeType start, RangeType end, ValueType k) {
    if (right < start || end < left)
      return;
    if (start <= left && right <= end) {
      // TODO
      this->tag += k;
      this->value += k * interval_size();
    } else {
      push_down();
      left_node().update(start, end, k);
      right_node().update(start, end, k);
      this->pull_up();
    }
  }
};
