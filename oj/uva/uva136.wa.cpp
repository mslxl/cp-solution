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

std::priority_queue<ull, std::vector<ull>, std::less<ull>> queue;
std::set<ull> already;

void ugly_produce(ull num) {
    int pp[] = {2, 3, 5};
    for (auto item : pp) {
        ull re = item * num;
        if (!already.count(re)) {
            already.insert(re);
            queue.push(re);
        }
    }
}

void each_tri(int times) {
    if (times == 0)
        return;
    ull top = queue.top();
    queue.pop();
    each_tri(times - 1);
    ugly_produce(top);
    if (!already.count(top)) {
        queue.push(top);
    }
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    queue.push(1); already.insert(1);
    queue.push(2); already.insert(2);
    queue.push(3); already.insert(3);

    while (already.size() < 1500) {
        each_tri(3);
    }
    while (already.size() > 1500)
        queue.pop();
    std::cout << queue.top() << std::endl;

    return 0;
}