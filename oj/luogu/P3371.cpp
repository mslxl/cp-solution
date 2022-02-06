#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

typedef long long ll;
const int UNREACHABLE = INT_MAX;

struct Node {
  int from, to, w;
  Node *next = nullptr; // 链表前项星
  Node(int from, int to, int w) : from(from), to(to), w(w), next(nullptr) {}
};

// 实现小根堆
struct PairFunctorImpl {
  bool operator()(const std::pair<int, int> &lhs,
                  const std::pair<int, int> &rhs) {
    return lhs.second > rhs.second;
  }
};

void dj(std::vector<Node *> &G, std::vector<int> &min_distance, int start) {
  std::vector<bool> vis(G.size(), false);

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      PairFunctorImpl>
      queue;

  min_distance[start] = 0;
  queue.push(std::make_pair(start, 0));

  while (!queue.empty()) {
    auto pt = queue.top();
    queue.pop();
    if (vis[pt.first])
      continue;

    // std::cout << "Mark " << pt.first << " which distance is " << pt.second
    //           << std::endl;

    Node *node = G[pt.first];

    for (; node != nullptr; node = node->next) { //
      int current_2_distance = node->w + pt.second;
      if (current_2_distance < min_distance[node->to]) {
        min_distance[node->to] = current_2_distance;
      }
      // std::cout << "Push " << pt.first << " --> " << node->to
      //           << " which distance is " << min_distance[node->to] <<
      //           std::endl;
      queue.push(std::make_pair(node->to, min_distance[node->to]));
    }
    // std::cout << "--------" << std::endl;
    vis[pt.first] = true;
  }
}

void add_edge(std::vector<Node *> &G, int from, int to, int w) {
  if (G[from] == nullptr) {
    G[from] = new Node(from, to, w);
  } else {
    Node *s = G[from];
    for (; s->next != nullptr; s = s->next) {
    }
    s->next = new Node(from, to, w);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int num_dot, num_edge, start;
  std::cin >> num_dot >> num_edge >> start;
  std::vector<Node *> G(num_dot + 1, nullptr);
  std::vector<int> min_distance(num_dot + 1, UNREACHABLE);
  for (int i = num_edge; i-- > 0;) {
    int u, v, w;
    std::cin >> u >> v >> w;
    // G[u] = Node{v, w};
    add_edge(G, u, v, w);
  }
  dj(G, min_distance, start);

  for (auto iter = min_distance.cbegin() + 1; iter != min_distance.cend();
       iter++) {
    std::cout << *iter << ' ';
  }

  return 0;
}
