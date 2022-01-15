#include <cmath>
#include <iostream>
#define DB
struct Nation {
    int idx;
    int ability;
};

std::ostream& operator<<(std::ostream& os, const Nation& ns) {
    return os << '(' << ns.idx << ',' << ns.ability << ')';
}

int solve(Nation* begin, Nation* end) {
    int len = end - begin;
    if (len == 2) {
        if (begin->ability > (end - 1)->ability) {
            return (end - 1)->idx;
        } else {
            return begin->idx;
        }
    }
#ifdef DB
    auto cp = begin;
    while (cp != end) {
        std::cout << *cp;
        cp++;
    }
    std::cout << std::endl;

#endif

    Nation* ns = new Nation[len / 2];
    for (int i = 0; i < len; i += 2) {
        int newPos = i / 2;
        Nation* ptr = ns + newPos;
        if (begin[i].ability > begin[i + 1].ability) {
            ptr->idx = begin[i].idx;
            ptr->ability = begin[i].ability;
        } else {
            ptr->idx = begin[i + 1].idx;
            ptr->ability = begin[i + 1].ability;
        }
    }
    int result = solve(ns, ns + (len / 2));
    delete[] ns;
    return result;
}

int main() {
    int n;
    std::cin >> n;
    n = pow(2, n);
    Nation* ns = new Nation[n];
    for (int i = 0; i < n; i++) {
        int ab;
        ns[i].idx = i + 1;
        std::cin >> ns[i].ability;
    }
    std::cout << solve(ns, ns + n);

    delete[] ns;
}