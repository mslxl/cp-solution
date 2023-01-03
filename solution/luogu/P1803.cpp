/**
 * @file P1803.cpp
 * @author mslxl
 * @brief 区间覆盖（线段树实现） 贪心
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <algorithm>
#include <cstring>
#include <iostream>
struct Contest {
    int start;
    int end;
    int span() const { return this->end - this->start; }
    bool operator<(const Contest& rhs) const {
        if (this->end < rhs.end) {
            return true;
        } else if (this->end == rhs.end && this->start > rhs.start) {
            return true;
        }
        return false;
    }
};

bool tree[1000000 * 6];
bool lazy[1000000 * 6];

inline void pull_up(int node) {
    tree[node] = tree[node * 2 + 1] || tree[node * 2 + 2];
}

inline void push_down(int node) {
    if (lazy[node]) {
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        tree[left_node] = tree[right_node] = lazy[node];
        lazy[right_node] = lazy[left_node] = lazy[node];
    }
}

bool is_filled(int left, int right, int start, int end, int node) {
    if (right < start || end < left)
        return false;
    push_down(node);
    if (start <= left && right <= end)
        return tree[node];
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    int mid = (left + right) / 2;
    return is_filled(left, mid, start, end, left_node) ||
           is_filled(mid + 1, right, start, end, right_node);
}
void set_tree(int left, int right, int start, int end, int node, bool value) {
    if (right < start || end < left)
        return;
    if (start <= left && right <= end) {
        tree[node] = value;
        lazy[node] = value;
        return;
    }
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    int mid = (left + right) / 2;
    set_tree(left, mid, start, end, left_node, value);
    set_tree(mid + 1, right, start, end, right_node, value);
    pull_up(node);
}

std::istream& operator>>(std::istream& is, Contest& contest) {
    is >> contest.start >> contest.end;
    return is;
}

int n;
Contest* cts;
bool* selected;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    cts = new Contest[n];
    for (int i = 0; i < n; i++) {
        Contest& elem = cts[i];
        std::cin >> elem;
    }
    std::sort(cts, cts + n);
    int selectedNum = 0;
    selected = new bool[n];
    memset(selected, false, sizeof(selected));
    bool haveChoose = true;
    while (haveChoose) {
        haveChoose = false;
        for (int i = 0; i < n; i++) {
            if (!is_filled(0, 1000000, cts[i].start, cts[i].end - 1, 0) &&
                !selected[i]) {
                haveChoose = true;
                selected[i] = true;
                selectedNum++;
                set_tree(0, 1000000, cts[i].start, cts[i].end - 1, 0, true);
                // std::cout << "Select " << cts[i].start << " -> " << cts[i].end
                //           << std::endl;
            }
        }
    }
    std::cout << selectedNum;
    return 0;
}
