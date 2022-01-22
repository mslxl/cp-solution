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

    constexpr RangeType mid() {
      return this->left + (this->right - this->left) / 2;
    }
    constexpr RangeType interval_size() { return this->right - this->left + 1; }

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
      Node &ln = left_node();
      Node &rn = right_node();
      ln.value =
          ln.value * this->lazy_multiply + this->lazy_add * ln.interval_size();
      ln.lazy_multiply = ln.lazy_multiply * this->lazy_multiply;
      ln.lazy_add = ln.lazy_add * this->lazy_multiply + this->lazy_add;

      rn.value =
          rn.value * this->lazy_multiply + this->lazy_add * rn.interval_size();
      rn.lazy_multiply = rn.lazy_multiply * this->lazy_multiply;
      rn.lazy_add = rn.lazy_add * this->lazy_multiply + this->lazy_add;
      this->lazy_multiply = 1;
      this->lazy_add = 0;
    }

    void multiply_interval(RangeType start, RangeType end, ValueType value) {
      if (right < start || end < left)
        return;
      if (start <= left && right <= end) {
        this->value = this->value * value;
        this->lazy_multiply = this->lazy_multiply * value;
        this->lazy_add = this->lazy_add * value;
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
  { // Basic add test
    SegTree<int, int> st(1, 50);
    st.add_interval(1, 50, 1);
    assert(st.ask_interval(1, 50) == 50);
    st.add_interval(20, 40, -1);
    assert(st.ask_interval(1, 10) == 10);
    assert(st.ask_interval(20, 40) == 0);
    st.destroy();
  }
  { // Build from array
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SegTree<int, int> st(arr, arr + 10, 1);
    for (int i = 1; i <= 10; i++) {
      assert(st.ask_interval(i, i) == i);
    }
  }
  { // Multiply
    SegTree<int, int> st(1, 50);
    st.multiply_interval(1, 50, 0);
    assert(st.ask_interval(1, 50) == 0);
    assert(st.ask_interval(1, 7) == 0);
    assert(st.ask_interval(40, 40) == 0);

    st.multiply_interval(1, 50, 50);
    assert(st.ask_interval(1, 50) == 0);
    assert(st.ask_interval(1, 7) == 0);
    assert(st.ask_interval(40, 40) == 0);

    st.add_interval(1, 50, 1);
    assert(st.ask_interval(1, 50) == 50);

    st.multiply_interval(1, 1, 50);
    assert(st.ask_interval(30, 30) == 1);
    assert(st.ask_interval(1, 1) == 50);
    assert(st.ask_interval(1, 10) == 59);

    st.multiply_interval(2, 5, 50);
    assert(st.ask_interval(1, 5) == 250);
    st.clear();
  }
  { // Simple compose
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    SegTree<int, int> st(arr, arr + 10, 1);
    assert(st.ask_interval(1, 10) == 550);
    st.add_interval(1, 5, 10);
    assert(st.ask_interval(1, 10) == 600);
    st.multiply_interval(1, 3, 10);
    assert(st.ask_interval(1, 10) == 1410);
    st.add_interval(2, 5, 100);
    assert(st.ask_interval(1, 10) == 1810);
    st.add_interval(4, 9, 100);
    assert(st.ask_interval(1, 10) == 2410);
    st.clear();
  }
  { // Data from P3373
    long long arr[] = {5929, 7152, 8443, 6028, 8580, 5449, 8473, 4237};
    SegTree<int, long long> st(arr, arr + 8, 1);
    st.add_interval(4, 8, 4376);
    st.multiply_interval(2, 8, 9637);
    st.add_interval(2, 6, 7918);
    st.add_interval(5, 8, 5681);
    assert(st.ask_interval(2, 8) % 571373 == 478836);
    st.clear();
  }

  std::cout << "Test passed!" << std::endl;
  return 0;
}
