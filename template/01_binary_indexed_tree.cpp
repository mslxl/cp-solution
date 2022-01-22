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

/**
 * 用树状数组维护的前缀和数组
 * 单点修改，区间查询
 * */
class BITPrefixSum {

public:
  std::size_t real_size;
  int *data = nullptr;
  static std::size_t parent_node(std::size_t idx) { return idx + lowbit(idx); }

  BITPrefixSum(std::size_t arr_size) {
    real_size = arr_size + 1;
    data = new int[real_size];
    std::memset(data, 0, sizeof(int) * real_size);
  }
  BITPrefixSum(int *begin, int *end) : BITPrefixSum(end - begin) {
    build_from(begin, end);
  }

  void build_from(int *begin, int *end) {
    clear();
    for (int idx = 0; begin != end; begin++, idx++) {
      add(idx, *begin);
    }
  }

  void destroy() { delete[] data; }
  void clear() { std::memset(data, 0, sizeof(int) * real_size); }

  static std::size_t lowbit(std::size_t idx) { return idx & -idx; }

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
};

/**
 * 用树状数组的前缀和维护的差分数组
 * 区间修改，区间(单点)查询
 * */
class BITDifference {

protected:
  BITPrefixSum *data;
  BITPrefixSum *data_mul_i;

  void internal_add(std::size_t idx, int value) {
    data->add(idx, value);
    data_mul_i->add(idx, value * (idx + 1));
  }

public:
  BITDifference(std::size_t arr_size) {
    data = new BITPrefixSum(arr_size);
    data_mul_i = new BITPrefixSum(arr_size);
  }

  BITDifference(int *begin, int *end) : BITDifference(end - begin) {
    build_from(begin, end);
  }

  void build_from(int *begin, int *end) {
    clear();
    internal_add(0, *begin);
    begin++;
    for (int idx = 1; begin != end; begin++, idx++) {
      internal_add(idx, *begin - *(begin - 1));
    }
  }

  void destroy() {
    data->destroy();
    data_mul_i->destroy();
    delete data;
    delete data_mul_i;
  }
  void clear() {
    data->clear();
    data_mul_i->clear();
  }

  std::size_t size() const { return data->size(); }

  int ask(std::size_t idx) const { return data->ask_prefix_sum(idx); }

  void add_interval(std::size_t left, std::size_t right, int value) {
    internal_add(left, value);
    internal_add(right + 1, -value);
  }

  int ask_prefix_sum(std::size_t idx) {
    // fast way
    // idx++; // 右移一位以适配 idx == 0
    // int ans = 0;
    // for (int i = idx; i != 0; i -= BITPrefixSum::lowbit(i)) {
    //   // 因为 idx 右移，公式变化
    //   ans += (idx + 1) * data->data[i] - data_mul_i->data[i];
    // }
    // return ans;
    return (idx + 2) * data->ask_prefix_sum(idx) -
           data_mul_i->ask_prefix_sum(idx);
  }

  int ask_interval(std::size_t left, std::size_t right) {
    return ask_prefix_sum(right) - ask_prefix_sum(left - 1);
  }

  void add(std::size_t idx, int value) { add_interval(idx, idx, value); }
};

int main() {
  { // 基础测试
    BITPrefixSum b(32);
    b.add(3, 1);
    b.add(4, 2);
    b.add(31, 5);
    assert(b.ask_prefix_sum(2) == 0);
    assert(b.ask_period(3, 4) == 3);
    assert(b.ask_period(0, 31) == 8);
    assert(b.ask_prefix_sum(5) == 3);
    assert(b.ask_prefix_sum(4) == 3);
    b.destroy();
  }
  {
    // data from P3374
    BITPrefixSum b(6);
    int arr[] = {0, 1, 5, 4, 2, 3};
    b.build_from(arr, arr + 6);
    b.add(1, 3);
    assert(b.ask_period(2, 5) == 14);
    b.add(3, -1);
    b.add(4, 2);
    assert(b.ask_period(1, 4) == 16);
    b.destroy();
  }

  { // 差分数组基础测试
    BITDifference b(32);
    b.add_interval(0, 10, 2);
    b.add_interval(5, 9, 2);
    assert(b.ask(10) == 2);
    assert(b.ask(5) == 4);
    assert(b.ask(4) == 2);
    assert(b.ask(10) == 2);

    b.clear();
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    b.build_from(arr, arr + 7);
    for (int i = 0; i < 7; i++) {
      assert(b.ask(i) == i + 1);
    }
    b.add_interval(0, 3, 10);
    for (int i = 0; i <= 3; i++) {
      assert(b.ask(i) == (i + 1) + 10);
    }
    for (int i = 4; i < 7; i++) {
      assert(b.ask(i) == (i + 1));
    }
    b.destroy();
  }
  { // data from P3368
    BITDifference b(6);
    int arr[] = {0, 1, 5, 4, 2, 3};
    b.build_from(arr, arr + 6);
    assert(b.ask(4) == 2);
    assert(b.ask(5) == 3);
    b.add_interval(2, 4, 2);
    assert(b.ask(3) == 6);
    b.add_interval(1, 5, -1);
    b.add_interval(3, 5, 7);
    assert(b.ask(4) == 10);
  }

  { // 区间修改，区间查询
    BITDifference b(11);

    b.add_interval(0, 10, 10);
    assert(b.ask(5) == 10);
    assert(b.ask(0) == 10);
    assert(b.ask_prefix_sum(0) == 10);
    assert(b.ask_prefix_sum(1) == 20);
    b.add_interval(2, 5, -10);
    assert(b.ask_prefix_sum(2) == 20);
    assert(b.ask_interval(0, 5) == 20);
  }

  printf("Test passed!\n");
}
