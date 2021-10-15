#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using std::string;
typedef long long ll;
typedef unsigned long long ull;

const int coeff[] = {2, 3, 5};

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    std::priority_queue<ull, std::vector<ull>, std::greater<ull>> pq;
    std::set<ull> s;
    pq.push(1);
    s.insert(1);
    for (int i = 1;; i++) {
        ull x = pq.top();
        pq.pop();
        if (i == 1500) {
            std::cout << "The 1500'th ugly number is " << x << "." << std::endl;
            break;
        }
        for (int j = 0; j < 3; j++) {
            ull x2 = x * coeff[j];
            if (!s.count(x2)) {
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
    return 0;
}