#include <bits/stdc++.h>
#include <functional>
#include <queue>

int main() {
  int n;
  std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int v;
    std::cin >> v;
    heap.push(v);
  }

  using ll = long long;
  ll cost = 0;

  while(heap.size() != 1){
    auto a = heap.top(); 
    heap.pop();
    auto b = heap.top();
    heap.pop();
    cost+=(a+b);
    heap.push(a+b);
  }
  std::cout << cost;
}