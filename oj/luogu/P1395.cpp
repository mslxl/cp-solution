#include <cstdio>
#include <map>
#include <set>
const int maxn = 5 * 10e4 + 10;
int n;

struct Node {
    std::set<Node*> pt;
    int value;
    bool is_connect(int id) const { return this->ptr.count(id); }
    void connect(Node& node) {
        this->pt.insert(&node);
        node.pt.insert(&value);
    }
    bool operator<(const Node& rhs) const { return this->value < rhs.value; }
};
Node* root;
std::map<int, Node*> map;

Node* get_node(int value) {
    if (map.count(value)) {
        return map[value];
    } else {
        Node* node = new Node();
        node->value = value;
        map[value] = node;
        return node;
    }
}

int solve(Node* place, std::set<Node> &vis){

}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int from, to;
        scanf("%d%d", &from, &to);
        auto node_from = get_node(from), node_to = get_node(to);
        node_from->connect(node_to);
    }
}