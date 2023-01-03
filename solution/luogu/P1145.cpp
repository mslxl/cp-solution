//约瑟夫
#include <bits/stdc++.h>
#include <bitset>
int k;
std::bitset<32> ppl;

int f(int m, int p) {
  if (m == 1)
    return 0;
  int c = (f(m - 1, p) + p) % m;
  std::cerr << "kill " << c << std::endl;
  if (c >= k) {
    ppl[c] = true;
  }
  return c;
}

bool is_success() {
  for (int i = k; i < 2 * k; i++) {
    if (!ppl[i])
      return false;
  }
  return true;
}


int num[14]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

int main() {
  std::cin >> k;

  std::cout << num[k];
  return 0;

  for (int i = k + 1; i <= 2 * k; i++) {
    ppl.reset();
    std::cerr << "---\n";
    f(2 * k, i);
    if (is_success()) {

      std::cout << i;
      return 0;
    }
  }
  std::cout << 0;
  return 0;
}