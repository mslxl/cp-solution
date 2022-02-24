#include <bits/stdc++.h>
int N, M;

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
    seq = new T[number_length * block_length + 1];
    std::memset(seq, 0, sizeof(T) * number_length * block_length);
  }

  inline T query(int left, int right) {
    int k = std::log2(right - left + 1);
    return op(access(left, k), access(right - (1 << k) + 1, k));
  }
  inline void destroy() { delete[] seq; }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> N >> M;
  ST<int, std::min> st(N);
  for (int i = 1; i <= N; i++) {
    std::cin >> st.access(i, 0);
  }
  st.update();
  for (int i = 1; i <= N - M + 1; i++) {
    std::cout << st.query(i, M + i - 1) << std::endl;
  }
  st.destroy();
  return 0;
}
