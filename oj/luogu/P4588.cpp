#include <cstdio>
typedef long long ll;
#define ValueType ll
#define RangeType ll
long long modd;
struct SegTreeNode {
  SegTreeNode *ptr_left_node = nullptr, *ptr_right_node = nullptr;
  RangeType left, right;
  ValueType value;
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
  SegTreeNode(RangeType l, RangeType r) : left(l), right(r), value(1) {}

  void pull_up() {
    this->value = (left_node().value * right_node().value) % modd;
  }

  void set(RangeType start, RangeType end, ValueType k) {
    if (right < start || end < left) {
      return;
    }
    if (start <= left && right <= end) {
      this->value = k;
    } else {
      left_node().set(start, end, k);
      right_node().set(start, end, k);
      this->pull_up();
    }
  }
  ValueType ask(RangeType start, RangeType end) {
    if (right < start || end < left)
      return 1;
    if (start <= left && right <= end) {
      return this->value;
    } else {
      return (left_node().ask(start, end) * right_node().ask(start, end)) %
             modd;
    }
  }
  void clear() {
    if (ptr_left_node != nullptr) {
      left_node().clear();
      delete ptr_left_node;
      ptr_left_node = nullptr;
    }
    if (ptr_right_node != nullptr) {
      right_node().clear();
      delete ptr_right_node;
      ptr_right_node = nullptr;
    }
  }
};

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll Q;
    ll op, x;
    SegTreeNode st(1, Q + 1);
    scanf("%lld%lld", &Q, &modd);
    for (int i = 1; i <= Q; i++) {
      scanf("%lld%lld", &op, &x);
      if (op == 1) {
        st.set(i, i, x);
      } else {
        st.set(x, x, 1);
      }
      printf("%lld\n", st.ask(1, Q + 1) % modd);
    }
    st.clear();
  }
  return 0;
}
