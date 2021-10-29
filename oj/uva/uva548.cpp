#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
typedef long long ll;
typedef unsigned long long ull;

struct Node {
    Node* left;
    Node* right;
    int value;
    Node() : left(nullptr), right(nullptr), value(0) {}
};

Node* root;

std::vector<int> read_list() {
    std::vector<int> list;
    std::string line;
    if (!getline(std::cin, line)) {
        return list;
    }
    std::stringstream ss;
    ss << line;
    int e;
    while (ss >> e) {
        list.push_back(e);
    }
    return list;
}

Node* build_tree(std::vector<int>::const_iterator inOrderBegin,
                 std::vector<int>::const_iterator inOrderEnd,
                 std::vector<int>::const_iterator postBegin,
                 std::vector<int>::const_iterator postEnd) {
    if (inOrderBegin >= inOrderEnd)
        return nullptr;
    auto value_base = *(postEnd - 1);
    Node* base = new Node();
    base->value = value_base;

    auto p = inOrderBegin;
    while (*p != value_base)
        p++;

    auto cnt = p - inOrderBegin;

    base->left = build_tree(inOrderBegin, p, postBegin, postBegin + cnt);
    base->right = build_tree(p + 1, inOrderEnd, postBegin + cnt, postEnd - 1);
    return base;
}
int best, best_sum;
void dfs(Node* node, int sum) {
    sum += node->value;
    if (node->left == nullptr && node->right == nullptr) {
        if (sum < best_sum) {
            best = node->value;
            best_sum = sum;
        } else if (sum == best_sum) {
            best = std::min(best, node->value);
        }
    }
    if (node->left != nullptr)
        dfs(node->left, sum);
    if (node->right != nullptr)
        dfs(node->right, sum);
}
void remove_tree(Node* n) {
    if (n == nullptr) {
        return;
    }
    remove_tree(n->left);
    remove_tree(n->right);
    delete n;
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    while (true) {
        std::vector<int> b1 = read_list();
        if (b1.empty())
            break;
        std::vector<int> b2 = read_list();
        if (b2.empty())
            break;
        root = build_tree(b1.cbegin(), b1.cend(), b2.cbegin(), b2.cend());
        best_sum = INT_MAX;
        dfs(root, 0);
        std::cout << best << std::endl;
        remove_tree(root);
    }

    return 0;
}