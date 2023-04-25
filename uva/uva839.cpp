#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
typedef long long ll;
typedef unsigned long long ull;

struct Node {
    Node *left;
    Node *right;
    int left_d;
    int right_d;
    int value;
    bool has_value;

    Node()
            : left(nullptr),
              right(nullptr),
              value(0),
              left_d(0),
              right_d(0),
              has_value(false) {}
};

Node *root;

Node *read_nodes() {
    Node *node = new Node();
    int W1, D1, W2, D2;
    std::cin >> W1 >> D1 >> W2 >> D2;
    node->left_d = D1;
    node->right_d = D2;
    if (W1 == 0) {
        node->left = read_nodes();
    } else {
        node->left = new Node();
        node->left->has_value = true;
        node->left->value = W1;
    }
    if (W2 == 0) {
        node->right = read_nodes();
    } else {
        node->right = new Node();
        node->right->has_value = true;
        node->right->value = W2;
    }
    return node;
}

void remove_nodes(Node *base) {
    if (base == nullptr)
        return;
    remove_nodes(base->left);
    remove_nodes(base->right);
    delete base;
}

bool banl = true;

int solve(Node *base) {
    if (base->has_value) {
        return base->value;
    }
    int d_l = solve(base->left), d_r = solve(base->right);
    if (!banl) {
        return d_l + d_r;
    } else if (base->left_d * d_l != base->right_d * d_r) {
        banl = false;
    }
    return d_l + d_r;
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        root = read_nodes();
        banl = true;
        solve(root);
        std::cout << (banl ? "YES" : "NO") << std::endl;
        if (T != 0) {
            std::cout << std::endl;
        }

        remove_nodes(root);
    }

    return 0;
}