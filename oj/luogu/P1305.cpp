#include <iostream>
#include <map>
#include <string>
struct Node {
    Node* left;
    Node* right;
    char value;
    bool isEmpty() const { return this->value == '*'; }
    Node() : left(nullptr), right(nullptr), value('*') {}
};
Node* root = nullptr;
std::map<char, Node*> nodes;

Node* getNode(char value) {
    return nodes.count(value) ? nodes[value] : ([value]() -> Node* {
        auto n = new Node();
        n->value = value;
        nodes[value] = n;
        return n;
    })();
}

void processLine(const std::string& line) {
    auto base = getNode(line[0]);
    if (root == nullptr || (line[1] != '*' && nodes.count(line[1])) ||
        (line[2] != '*' && nodes.count(line[2]))) {
        root = base;
    }
    base->left = getNode(line[1]);
    base->right = getNode(line[2]);
}
void dfs(const Node* base) {
    if (base == nullptr) {
        return;
    }
    std::cout << base->value;
    dfs(base->left);
    dfs(base->right);
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::string wd;
    nodes['*'] = nullptr;
    while (n--) {
        std::cin >> wd;
        processLine(wd);
    }
    dfs(root);
    return 0;
}