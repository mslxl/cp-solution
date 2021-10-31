#include <algorithm>
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

std::map<int, int> memo;
std::set<int> idxs;

struct Node {
    Node* left;
    Node* right;
    int value;
    bool has_value;
    Node() : left(nullptr), right(nullptr), value(0), has_value(false) {}
};

Node* root = nullptr;

Node* read_tree() {
    Node* n = new Node();
    std::cin >> n->value;
    if (n->value == -1) {
        return nullptr;
    }
    n->has_value = true;
    n->left = read_tree();
    n->right = read_tree();
    return n;
}
int pos = 0;
void eval(Node* node) {
    if (!idxs.count(pos)) {
        memo[pos] = 0;
        idxs.insert(pos);
    }
    int& value = memo[pos];
    if (node->has_value) {
        value += node->value;
    }
    if (node->left != nullptr) {
        pos--;
        eval(node->left);
        pos++;
    }
    if (node->right != nullptr) {
        pos++;
        eval(node->right);
        pos--;
    }
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int idx = 1;
    root = read_tree();
    while (root != nullptr) {
        pos = 0;
        memo.clear();
        idxs.clear();
        std::cout << "Case " << idx++ << ':' << std::endl;
        eval(root);
        int idx_ids = 1;
        for (auto i : idxs) {
            std::cout << memo[i];
            if(idx_ids++ != idxs.size()){
                std::cout << ' ';
            }
        }
        root = read_tree();
        std::cout << std::endl << std::endl;
    }

    return 0;
}