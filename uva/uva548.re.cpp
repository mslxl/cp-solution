#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#define iter std::vector<int>::const_iterator

const int maxn = 10e6;
int tree[maxn] = {0};

std::vector<int> read_line() {
  std::vector<int> ret;
  std::string line;
  std::getline(std::cin, line);
  std::stringstream ss;
  ss << line;
  int num;
  for (int i = 0; ss >> num; i++) {
    ret.push_back(num);
  }
  return ret;
}

constexpr int left_node(int node) { return node * 2 + 1; }
constexpr int right_node(int node) { return node * 2 + 2; }

void build(std::size_t node, iter in_begin, iter in_end, iter post_begin,
           iter post_end) {
  if (in_begin >= in_end)
    return;
  int base = *(post_end - 1);

  // iter in_order_split = std::find(in_begin, in_end, base);
  iter in_order_split = in_begin;
  while (*in_order_split != base) {
    in_order_split++;
  }

  tree[node] = base;

  int left_node_cnt = in_order_split - in_begin;

  build(right_node(node), in_order_split + 1, in_end,
        post_begin + left_node_cnt, post_end - 1);

  build(left_node(node), in_begin, in_order_split, post_begin,
        post_begin + left_node_cnt);
}
bool is_leaf(int node) {
  return tree[left_node(node)] == 0 && tree[right_node(node)] == 0;
}

int min_sum = INT_MAX, min_leaf = INT_MAX;
void dfs(int node, int sum) {
  if (tree[node] == 0)
    return;

  sum += tree[node];
  if (is_leaf(node)) {
    if (sum < min_sum) {
      min_sum = sum;
      min_leaf = tree[node];
    } else if (sum == min_sum) {
      min_leaf = std::min(tree[node], min_leaf);
    }
  } else {
    if (tree[left_node(node)] != 0)
      dfs(left_node(node), sum);
    if (tree[right_node(node)] != 0)
      dfs(right_node(node), sum);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  while (!std::cin.eof()) {
    auto in_order_seq = read_line();
    auto post_order_seq = read_line();
    if (in_order_seq.empty() || post_order_seq.empty()) {
      break;
    }
    std::memset(tree, 0, sizeof(tree));
    min_sum = INT_MAX;
    min_leaf = INT_MAX;
    build(0, in_order_seq.cbegin(), in_order_seq.cend(),
          post_order_seq.cbegin(), post_order_seq.cend());
    dfs(0, 0);
    std::cout << min_leaf << std::endl;
  }
}
