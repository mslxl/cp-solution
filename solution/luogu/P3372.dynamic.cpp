#include <cassert>
#include <cstdlib>
#include <iostream>
/**
 * 动态开点线段树
 * */

template <typename RangeType = int, typename ValueType = int> class SegTree {
public:
  class Node {
  private:
    Node *ptr_left_node = nullptr;
    Node *ptr_right_node = nullptr;

    RangeType mid() { return this->left + (this->right - this->left) / 2; }
    RangeType interval_size() { return this->right - this->left + 1; }

    ValueType lazy_add = 0, lazy_multiply = 1;

  public:
    ValueType left, right;
    ValueType value;
    Node(RangeType l, RangeType r, ValueType v = 0)
        : left(l), right(r), value(v){};

    Node &left_node() {
      if (ptr_left_node == nullptr) {
        ptr_left_node = new Node(left, mid());
      }
      return *ptr_left_node;
    }

    Node &right_node() {
      if (ptr_right_node == nullptr) {
        ptr_right_node = new Node(mid() + 1, right);
      }
      return *ptr_right_node;
    }

    void pull_up() { this->value = left_node().value + right_node().value; }
    void push_down() {
      auto &ln = left_node();
      auto &rn = right_node();
      if (lazy_multiply != 1) {
        ln.value *= lazy_multiply;
        ln.lazy_add *= lazy_multiply;
        ln.lazy_multiply *= lazy_multiply;

        rn.value *= lazy_multiply;
        rn.lazy_add *= lazy_multiply;
        rn.lazy_multiply *= lazy_multiply;

        lazy_multiply = 1;
      }
      if (lazy_add != 0) {
        ln.value += ln.interval_size() * this->lazy_add;
        ln.lazy_add += this->lazy_add;

        rn.value += rn.interval_size() * this->lazy_add;
        rn.lazy_add += this->lazy_add;
        lazy_add = 0;
      }
    }

    void multiply_interval(RangeType start, RangeType end, ValueType value) {
      if (right < start || end < left)
        return;
      if (start <= left && right <= end) {
        this->lazy_multiply *= value;
        this->lazy_add *= value;
        this->value *= value;
      } else {
        push_down();
        left_node().multiply_interval(start, end, value);
        right_node().multiply_interval(start, end, value);
        this->pull_up();
      }
    }

    void add_interval(RangeType start, RangeType end, ValueType value) {
      if (right < start || end < left)
        return;
      if (start <= left && right <= end) {
        this->lazy_add += value;
        this->value += value * interval_size();
      } else {
        push_down();
        left_node().add_interval(start, end, value);
        right_node().add_interval(start, end, value);
        this->pull_up();
      }
    }
    ValueType ask_interval(RangeType start, RangeType end) {
      if (right < start || end < left)
        return 0;

      if (start <= left && right <= end) {
        return this->value;
      } else {
        push_down();
        return left_node().ask_interval(start, end) +
               right_node().ask_interval(start, end);
      }
    }

    void desktroy() {
      if (ptr_left_node != nullptr) {
        ptr_left_node->desktroy();
        delete ptr_left_node;
        ptr_left_node = nullptr;
      }
      if (ptr_right_node != nullptr) {
        ptr_right_node->desktroy();
        delete ptr_right_node;
        ptr_right_node = nullptr;
      }
    }
    void build_from(ValueType *begin, ValueType *end) {
      if (right <= left) {
        this->value = *begin;
        return;
      }
      int mid_offset = (end - begin) / 2;
      left_node().build_from(begin, begin + mid_offset);
      right_node().build_from(begin + mid_offset + 1, end);
      this->pull_up();
    }
  };

  // ------ Wrapper --------
  SegTree(RangeType left, RangeType right) { root = new Node(left, right); }
  SegTree(ValueType *begin, ValueType *end, int offset = 0)
      : SegTree(offset, offset + end - begin - 1) {
    root->build_from(begin, end - 1);
  }

  void add_interval(RangeType start, RangeType end, ValueType value) {
    root->add_interval(start, end, value);
  }
  void multiply_interval(RangeType start, RangeType end, ValueType value) {
    root->multiply_interval(start, end, value);
  }
  ValueType ask_interval(RangeType start, RangeType end) {
    return root->ask_interval(start, end);
  }
  void destroy() { root->desktroy(); }
  void clear() { this->destroy(); }

private:
  Node *root;
};
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  auto *arr = new long long[n];
  for (int i = 0; i < n; i++) {
    scanf("%lld", arr + i);
  }
  SegTree<long long, long long> st(arr, arr + n, 1);
  int op, x, y, k;
  while (m--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%d", &x, &y, &k);
      st.add_interval(x, y, k);
    } else {
      scanf("%d%d", &x, &y);
      printf("%lld\n", st.ask_interval(x, y));
    }
  }

  return 0;
}
