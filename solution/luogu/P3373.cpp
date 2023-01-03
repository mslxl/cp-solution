#include <cstdlib>
#include <iostream>
/**
 * 动态开点线段树
 * */
int mod;

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
      ln.value = ((ln.value * this->lazy_multiply % mod) +
                  (this->lazy_add * ln.interval_size() % mod)) %
                 mod;
      ln.lazy_multiply = ln.lazy_multiply * this->lazy_multiply % mod;
      ln.lazy_add =
          ln.lazy_add * this->lazy_multiply % mod + this->lazy_add % mod;

      rn.value = (rn.value * this->lazy_multiply % mod +
                  this->lazy_add * rn.interval_size() % mod) %
                 mod;
      rn.lazy_multiply = rn.lazy_multiply * this->lazy_multiply % mod;
      rn.lazy_add =
          (rn.lazy_add * this->lazy_multiply % mod + this->lazy_add % mod) %
          mod;

      this->lazy_multiply = 1;
      this->lazy_add = 0;
    }

    void multiply_interval(RangeType start, RangeType end, ValueType value) {
      if (right < start || end < left)
        return;
      if (start <= left && right <= end) {
        this->value = (this->value * value) % mod;
        this->lazy_multiply = (this->lazy_multiply * value) % mod;
        this->lazy_add = (this->lazy_add * value) % mod;
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
        this->value += value * interval_size() % mod;
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
        return left_node().ask_interval(start, end) % mod +
               right_node().ask_interval(start, end) % mod;
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
  scanf("%d%d%d", &n, &m, &mod);
  long long *arr = new long long[n];
  for (int i = 0; i < n; i++) {
    scanf("%lld", arr + i);
  }
  SegTree<int, long long> st(arr, arr + n, 1);
  delete[] arr;
  int op, x, y, k;
  while (m--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%d", &x, &y, &k);
      st.multiply_interval(x, y, k % mod);
    } else if (op == 2) {
      scanf("%d%d%d", &x, &y, &k);
      st.add_interval(x, y, k % mod);
    } else if (op == 3) {
      scanf("%d%d", &x, &y);
      printf("%lld\n", st.ask_interval(x, y) % mod);
    }
  }
  return 0;
}
