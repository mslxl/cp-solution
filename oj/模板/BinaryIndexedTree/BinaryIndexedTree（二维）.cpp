#include <array>

namespace ojlib {
template <typename T>
inline typename std::enable_if<std::is_integral<T>::value, T>::type
lowbit(T x) {
  return (-x) & x;
}

template <typename T = int, std::size_t BitW = 5000, std::size_t BitH = BitW,
          typename = typename std::enable_if<std::is_integral<T>::value>::type>
struct BitII {
  std::array<std::array<T, BitW>, BitH> bit;

  void add(std::size_t x, std::size_t y, T v) {
    x++;
    y++;
    for (int i = x; i <= BitH; i += lowbit(i))
      for (int j = y; j <= BitW; j += lowbit(j))
        bit[i][j] += v;
  }

  T prefix(std::size_t x, std::size_t y) {
    x++;
    y++;
    T s = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
      for (int j = y; j > 0; j -= lowbit(i)) {
        s += bit[i][j];
      }
    }
    return s;
  }
  T sum_closerange(std::size_t x, std::size_t y, std::size_t w, std::size_t h) {
    return prefix(x + w, y + h) - prefix(x - 1, y + h) - prefix(x + w, y - 1) +
           prefix(x - 1, y - 1);
  }
};
} // namespace ojlib