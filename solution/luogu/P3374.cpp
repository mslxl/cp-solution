#include <cstdio>
#include <cstdlib>
#include <cstring>

class BIT {
private:
  std::size_t real_size;
  int *data = nullptr;

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
    idx++; // 向右偏移一位，让下标为 0 时能正常计算
    for (; idx < real_size; idx = parent_node(idx)) {
      data[idx] += value;
    }
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
  int n, m;
  int op, x, k;
  scanf("%d%d", &n, &m);
  BIT b(n + 1);
  b.clear();

  for (int i = 1; i <= n; i++) {
    int num;
    scanf("%d", &num);
    b.add(i, num);
  }

  while (m--) {
    scanf("%d%d%d", &op, &x, &k);
    if (op == 1) {
      b.add(x, k);
    } else if (op == 2) {
      printf("%d\n", b.ask_period(x, k));
    }
  }
}
