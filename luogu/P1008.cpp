
#include <cstdio>

bool is_include(int num, int src) {
    while (src > 0) {
        int a = src % 10;
        if (a == num)
            return true;
        src /= 10;
    }
    return false;
}

bool is_num_repeat(int num) {
    while (num > 0) {
        int a = num % 10;
        if (is_include(a, num / 10))
            return false;
        num /= 10;
    }
    return true;
}

bool is_legal(int a, int b, int c) {
    if (a * 2 == b && a * 3 == c && b + a == c) {
        bool legal = true;
        for (int i = 1; i < 10; ++i) {
            bool ab, bb, cb;
            ab = is_include(i, a);
            bb = is_include(i, b);
            cb = is_include(i, c);
            if (!((ab && !bb && !cb) ||
                  (!ab && bb && !cb) ||
                  (!ab && !bb && cb))) {
                legal = false;
            }
        }
        return legal;
    }
    return false;
}

int main() {
    for (int i = 100; i < 1000; ++i) {
        for (int j = i; j < 1000; j += i) {
            for (int k = j; k < 1000; k += i) {
                if (is_num_repeat(i) && is_num_repeat(j) && is_num_repeat(k) && is_legal(i, j, k)) {
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }
    return 0;
}