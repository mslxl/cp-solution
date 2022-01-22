/**
 *  树状数组
 *
 *  单点查询：O(log_{2}^n)
 *  区间查询：O(log_{2}^n)
 *  总复杂度：O(nlogn)
 *  */
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

class BIT {
private:
  std::size_t real_size;
  int *data = nullptr;
  // BIT *diff = nullptr;
  // void use_diff() {
  //   if (diff == nullptr) {
  //     diff = new BIT(real_size);
  //   }
  // }

public:
  BIT(std::size_t arr_size) {
    real_size = arr_size + 1;
    data = new int[real_size];
    std::memset(data, 0, sizeof(int) * real_size);
  }
  BIT(int *begin, int *end) : BIT(end - begin) { build_from(begin, end); }

  void build_from(int *begin, int *end) {
    clear();
    for (int idx = 0; begin != end; begin++, idx++) {
      add(idx, *begin);
    }
  }

  void destroy() { delete[] data; }
  void clear() { std::memset(data, 0, sizeof(int) * real_size); }

  static std::size_t lowbit(std::size_t idx) { return idx & -idx; }
  static std::size_t parent_node(std::size_t idx) { return idx + lowbit(idx); }

  std::size_t size() const { return real_size - 1; }

  void add(std::size_t idx, int value) {
    if (value == 0) {
      return;
    }
    idx++; // 向右偏移一位，让下标为 0 时能正常计算
    for (; idx < real_size; idx = parent_node(idx)) {
      data[idx] += value;
    }
  }
  void set(std::size_t idx, int value) {
    int diff = value - ask(idx);
    add(idx, diff);
  }

  int ask_prefix_sum(std::size_t idx) const {
    idx++; // 向右偏移一位，让下标为 0 时能正常计算
    int ans = 0;
    for (; idx; idx -= lowbit(idx)) {
      ans += data[idx];
    }
    return ans;
  }
  int ask(std::size_t idx) const {
    return ask_prefix_sum(idx) - ask_prefix_sum(idx - 1);
  }

  int ask_period(std::size_t left, std::size_t right) const {
    return ask_prefix_sum(right) - ask_prefix_sum(left - 1);
  }

  void DEBUG_OUTPUT_VALUE(std::size_t left = 0,
                          std::size_t right = 0x3f3f3f) const {
    if (right == 0x3f3f3f)
      right = size();
    printf("{");
    for (; left <= right; left++) {
      printf("%d, ", ask(left));
    }
    printf("}");
  }
  void DEBUG_OUTPUT_NODE(std::size_t left = 0,
                         std::size_t right = 0x3f3f3f) const {
    if (right == 0x3f3f3f)
      right = size();
    printf("{");
    for (; left <= right; left++) {
      printf("%d, ", data[left + 1]);
    }
    printf("}");
  }
};

int main() {
  {
    BIT b(32);
    b.add(3, 1);
    b.add(4, 2);
    assert(b.ask_prefix_sum(2) == 0);
    assert(b.ask_period(3, 4) == 3);
    assert(b.ask_prefix_sum(5) == 3);
    assert(b.ask_prefix_sum(4) == 3);
    b.destroy();
  }
  {
    // data from P3374
    BIT b(6);
    int arr[] = {0, 1, 5, 4, 2, 3};
    b.build_from(arr, arr + 6);
    b.DEBUG_OUTPUT_VALUE(0, 5);
    printf("\n");
    b.add(1, 3);
    assert(b.ask_period(2, 5) == 14);
    b.add(3, -1);
    b.add(4, 2);
    assert(b.ask_period(1, 4) == 16);
  }
}
