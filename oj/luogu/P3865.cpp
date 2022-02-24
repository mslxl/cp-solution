
#include <bits/stdc++.h>

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}

template <typename T, const T &(*op)(const T &, const T &)> class ST {
private:
  std::size_t number_length = 0;
  std::size_t block_length = 0;

  T *seq;

public:
  inline void update() {
    for (int j = 1; j <= block_length; j++) {
      for (int i = 1; i + (1 << j) - 1 <= number_length; i++) {
        access(i, j) = op(access(i, j - 1), access(i + (1 << (j - 1)), j - 1));
      }
    }
  }
  inline T &access(int i, int j) { return seq[i * block_length + j]; }
  inline ST(std::size_t len)
      : number_length(len + 1), block_length(log2(len + 1) + 1) {
    seq = new T[number_length * block_length];
    std::memset(seq, 0, sizeof(T) * number_length * block_length);
  }

  inline T query(int left, int right) {
    int k = std::log2(right - left + 1);
    return op(access(left, k), access(right - (1 << k) + 1, k));
  }
  inline void destroy() { delete[] seq; }
};

int N, M;

int main() {
  N = read();
  M = read();
  ST<int, std::max> table(N);
  for (int i = 1; i <= N; i++)
    table.access(i, 0) = read();
  table.update();

  while (M--) {
    int l = read(), r = read();
    printf("%d\n", table.query(l, r));
  }
  table.destroy();
  return 0;
}
