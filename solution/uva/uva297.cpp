#include <algorithm>
#include <cassert>
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
    Node* a;
    Node* b;
    Node* c;
    Node* d;
    char v;
    Node() : a(nullptr), b(nullptr), c(nullptr), d(nullptr), v('e') {}
};
Node* tree1 = nullptr;
Node* tree2 = nullptr;

Node* read_node(std::stringstream& ss) {
    if (!ss)
        return nullptr;
    Node* n = new Node();
    char ch;
    ss >> ch;
    if (ch == 'p') {
        n->a = read_node(ss);
        n->b = read_node(ss);
        n->c = read_node(ss);
        n->d = read_node(ss);
        n->v = 'p';
    } else if (ch == 'f') {
        n->v = 'f';
    } else if (ch == 'e') {
        n->v = 'e';
    }
    return n;
}
Node* read_tree() {
    std::stringstream ss;
    std::string line;
    getline(std::cin, line);
    ss << line;
    return read_node(ss);
}
void free_tree(Node* n) {
    if (n == nullptr)
        return;
    free_tree(n->a);
    free_tree(n->b);
    free_tree(n->c);
    free_tree(n->d);
    delete n;
}

Node* marge_tree(Node* c1, Node* c2) {
    if (c1 == nullptr)
        return new Node(*c2);
    else if (c2 == nullptr)
        return new Node(*c1);

    if (c1->v == 'e')
        return new Node(*c2);
    else if (c2->v == 'e')
        return new Node(*c1);

    if (c1->v == 'f')
        return new Node(*c1);
    else if (c2->v == 'f')
        return new Node(*c2);

    if (c1->v == 'p' && c2->v == 'p') {
        Node* n = new Node();
        n->a = marge_tree(c1->a, c2->a);
        n->b = marge_tree(c1->b, c2->b);
        n->c = marge_tree(c1->c, c2->c);
        n->d = marge_tree(c1->d, c2->d);
        n->v = 'p';
        return n;
    }
    assert(false);
}

int solve(Node* tree, int level = 1024) {
    if (tree->v == 'f')
        return level;
    else if (tree->v == 'e')
        return 0;
    else if (tree->v = 'p') {
        const int next_level = level / 4;
        return solve(tree->a, next_level) + solve(tree->b, next_level) +
               solve(tree->c, next_level) + solve(tree->d, next_level);
    }
    assert(false);
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;

    std::string line;
    getline(std::cin, line);
    while (T--) {
        tree1 = read_tree();
        tree2 = read_tree();
        Node* tree = marge_tree(tree1, tree2);
        std::cout << "There are " << solve(tree) << " black pixels."
                  << std::endl;
        // free_tree(tree1);
        // free_tree(tree2);
        // free_tree(tree);
    }

    return 0;
}