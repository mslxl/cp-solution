#include "debug.h"

#include <array>
#include <iostream>
#include <type_traits>
#include <vector>


namespace ojlib{
  template<typename T>
  inline typename std::enable_if<std::is_integral<T>::value, T>::type lowbit(T x){
    return (-x) & x;
  }

  template<typename T = int,std::size_t BitSize = 5000, typename = typename std::enable_if<std::is_integral<T>::value>::type>
  struct BitI{
    std::array<T, BitSize> bit;

    void add(std::size_t i, T v){
      i++;
      for(; i<=BitSize; i += lowbit(i))
        bit[i]+=v;
    }

    T prefix(std::size_t i){
      i++;
      T s = 0;
      for(; i>0; i-=lowbit(i))
        s+= bit[i];
      return s;
    }

    T sum_closerange(std::size_t l, std::size_t r){
      return prefix(r) - prefix(l-1);
    }
  };
}

// ------ test below -----

ojlib::BitI<int> bit;

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int num;
    std::cin >> num;
    bit.add(i,num);
  }
  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    std::cin >> l >> r;
    std::cout << bit.sum_closerange(l, r) << std::endl;
  }

  return 0;
}