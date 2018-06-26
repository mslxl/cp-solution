#include <iostream>
#include <cmath>

int *num = NULL;
int n, k;

bool isPrime(int number) {
    for (int i = 2; i <= sqrt(double(number)); ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

int run(int remain, int already, int start) {
    if (remain == 0) {
        return isPrime(already);
    }
    int primeNum = 0;
    for (int i = start; i < n; ++i) {
        primeNum += run(remain - 1, already + *(num + i), i + 1);
    }
    return primeNum;
}


int main() {
    std::cin >> n >> k;
    num = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> *(num + i);
    }

    std::cout << run(k, 0, 0);
    return 0;
}