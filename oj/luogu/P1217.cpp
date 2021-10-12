#include <iostream>
#include <cmath>

bool isPrime(int n) {
    for (int k = 2; k <= sqrt(n); ++k)
        if (n % k == 0)
            return false;
    return true;
}

int getSize(int n) {
    int m = 1, k = n;
    while (k > 9) {
        k /= 10;
        ++m;
    }
    return m;
}

int main() {
    int m, n, q, w;
    std::cin >> m >> n;
    q = getSize(m);
    w = getSize(n);
    if (q <= 1 && w >= 1) {
        if ((m <= 5) && (n >= 5))
            std::cout << 5 << std::endl;
        if ((m <= 7) && (n >= 7))
            std::cout << 7 << std::endl;
    }
    if ((q <= 2) && (w >= 2)) {
        if ((m <= 11) && (n >= 11))
            std::cout << 11 << std::endl;
    }
    if ((q <= 3) && (w >= 3)) {
        for (int a = 1; a <= 9; a += 2)
            for (int b = 0; b <= 9; ++b) {
                int f = a * 100 + b * 10 + a;
                if (f < m)
                    continue;
                if (f > n)
                    return 0;
                if (isPrime(f))
                    std::cout << f << std::endl;
            }
    }
    if ((q <= 5) && (w >= 5)) {
        for (int a = 1; a <= 9; a += 2)
            for (int b = 0; b <= 9; ++b)
                for (int c = 0; c <= 9; ++c) {
                    int f = a * 10000 + b * 1000 + c * 100 + b * 10 + a;
                    if (f < m)
                        continue;
                    if (f > n)
                        return 0;
                    if (isPrime(f))
                        std::cout << f << std::endl;
                }
    }

    if ((q <= 7) && (w >= 7)) {
        for (int a = 1; a <= 9; a += 2) {
            for (int b = 0; b <= 9; ++b) {
                for (int c = 0; c <= 9; ++c) {
                    for (int d = 0; d <= 9; ++d) {
                        int f = a * 1000000 + b * 100000 + c * 10000 + d * 1000 + c * 100 + b * 10 + a;
                        if (f < m) {
                            continue;
                        }

                        if (f > n) {
                            return 0;
                        }

                        if (isPrime(f)) {
                            std::cout << f << std::endl;
                        }

                    }
                }
            }
        }
    }
    return 0;
}