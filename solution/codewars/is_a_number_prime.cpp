#include <cmath>

bool isPrime(int n) {
  if(n <= 1) return false;
  for (int k = 2; k <= sqrt(n); ++k)
    if (n % k == 0)
      return false;
  return true;
}
