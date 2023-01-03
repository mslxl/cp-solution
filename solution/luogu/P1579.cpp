#include <iostream>
#include <cmath>

int n;

bool isPrime(int n) {
    for (int k = 2; k <= sqrt(n); ++k)
        if (n % k == 0)
            return false;
    return true;
}

int main() {
    std::cin >> n;
    for (int i = 2; i < n; i += 1) {
        for (int j = 2; j < n - i; j += 1) {
            for (int k = 2; k <= n - i - j; k += 1) {
                if (i + j + k == n) {
                    if (isPrime(i) && isPrime(j) && isPrime(k)) {
                        std::cout << i << " " << j << " " << k;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
