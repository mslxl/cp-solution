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
#define _br() std::cout << std::endl;
typedef long long ll;
typedef unsigned long long ull;

struct Node {
    bool has_value;
    int value;
    Node* left;
    Node* right;
    Node() : has_value(false), value(0), left(nullptr), right(nullptr) {}
};

int str2int(std::string wd) {
    int num = 0;
    for (auto ch : wd) {
        num *= 10;
        num += (ch - '0');
    }
    return num;
}

std::pair<int, std::string> ext_node(std::string wd) {
    int pos_comma = wd.find(",");
    auto node =
        std::make_pair(str2int(wd.substr(1, pos_comma - 1)),
                       wd.substr(pos_comma + 1, wd.size() - pos_comma - 2));
    return node;
}

Node root;
bool exist_dup = false;

void insert_node(int value, const char* location, Node* base) {
    if (strlen(location) == 0) {
        if (base->has_value) {
            exist_dup = true;
        } else {
            base->has_value = true;
            base->value = value;
        }
    } else {
        char n = *location;
        if (n == 'L') {
            if (base->left == nullptr) {
                base->left = new Node();
            }
            insert_node(value, location + 1, base->left);
        } else {
            if (base->right == nullptr) {
                base->right = new Node();
            }
            insert_node(value, location + 1, base->right);
        }
    }
}
bool bfs(std::vector<int>& ans) {
    // Copy from book
    std::queue<Node*> q;
    ans.clear();
    q.push(&root);
    while (!q.empty()) {
        Node* u = q.front();
        q.pop();
        if (!u->has_value)
            return false;
        ans.push_back(u->value);
        if (u->left != nullptr)
            q.push(u->left);
        if (u->right != nullptr)
            q.push(u->right);
    }
    return true;
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    std::string wd;
    while (std::cin >> wd) {
        if (wd == "()") {
            std::vector<int> ans;
            auto complate = bfs(ans);
            if (!complate || exist_dup) {
                std::cout << "not complete";
            } else {
                _for(idx, 0, ans.size()) {
                    std::cout << ans[idx];
                    if (idx != ans.size() - 1) {
                        std::cout << ' ';
                    }
                }
            }
            std::cout << std::endl;
            root = Node();
            exist_dup = false;
            continue;
        }
        auto nodeData = ext_node(wd);
        insert_node(nodeData.first, nodeData.second.c_str(), &root);
    }

    return 0;
}