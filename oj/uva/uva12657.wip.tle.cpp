#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
#define _br() std::cout << std::endl;
typedef long long ll;
typedef unsigned long long ull;

bool reverse = false;
struct Node {
    int value;
    Node* pre;
    Node* next;

    Node** pre_ptr() { return reverse ? &next : &pre; }
    Node** next_ptr() { return reverse ? &pre : &next; }
};
std::map<int, Node> prts;

Node head{-1, nullptr, nullptr};
Node tail{-2, nullptr, nullptr};

void insert_before(Node& base, Node& node) {
    node.pre = *base.pre_ptr();
    node.next = &base;
    (**base.pre_ptr()).next = &node;
    (*base.pre_ptr()) = &node;
}

void insert_after(Node& base, Node& node) {
    node.next = *base.next_ptr();
    node.pre = &base;
    (**base.next_ptr()).pre = &node;
    (*base.next_ptr()) = &node;
}

void swap_node(Node& n1, Node& n2) {
    std::swap(*n1.next_ptr(), *n2.next_ptr());
    std::swap(*n1.pre_ptr(), *n2.pre_ptr());
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int n, T;
    int cmd, X, Y;
    while (std::cin >> n >> T) {
        while (T--) {
            std::cin >> cmd;
            if (cmd == 4) {
            } else {
                std::cin >> X >> Y;
                if (cmd == 1) {
                }
            }
        }
    }
    return 0;
}