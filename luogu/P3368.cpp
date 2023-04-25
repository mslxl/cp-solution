#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

/**
 * 用树状数组维护的前缀和数组
 * 单点修改，区间查询
 * */
class BITPrefixSum {
protected:
  std::size_t real_size;
  int *data = nullptr;

  static std::size_t parent_node(std::size_t idx) { return idx + lowbit(idx); }

public:
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
 * 区间修改，单点查询
 * */
class BITDifference {

protected:
  BITPrefixSum *data;

public:
  BITDifference(std::size_t arr_size) { data = new BITPrefixSum(arr_size); }
  BITDifference(int *begin, int *end) : BITDifference(end - begin) {
    build_from(begin, end);
  }

  void build_from(int *begin, int *end) {
    clear();
    data->add(0, *begin);
    begin++;
    for (int idx = 1; begin != end; begin++, idx++) {
      data->add(idx, *begin - *(begin - 1));
    }
  }

  void destroy() { delete[] data; }
  void clear() { data->clear(); }

  std::size_t size() const { return data->size(); }

  int ask(std::size_t idx) const { return data->ask_prefix_sum(idx); }

  void add_interval(std::size_t left, std::size_t right, int value) {
    data->add(left, value);
    data->add(right + 1, -value);
  }

  void add(std::size_t idx, int value) { add_interval(idx, idx, value); }
};

int main() {
  int N, M;
  std::cin >> N >> M;
  int *arr = new int[N + 1];
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i + 1];
  }
  arr[0] = 0;
  BITDifference b(N + 1);
  b.build_from(arr, arr + N + 1);
  int op, x, y, k;
  while (M--) {
    std::cin >> op;
    if (op == 1) {
      std::cin >> x >> y >> k;
      b.add_interval(x, y, k);
    } else if (op == 2) {
      std::cin >> x;
      std::cout << b.ask(x) << std::endl;
    }
  }
  return 0;
}
