#include <bits/stdc++.h>
#ifdef Local
#define tout \
  if (1)     \
  std::cerr
#else
#define tout \
  if (0)     \
  std::cerr
#endif
typedef long long ll;
#define rep(i, s, e) for (int i = s; i < e; i++)

const int maxn = 2 * 1e5 + 17;

int verticals[maxn];
int horizontal[maxn];

int verticals_num[maxn];
int horizontal_num[maxn];

int v_edge_num = 0;
int h_edge_num = 0;

int v_edge_top = 0;
int h_edge_top = 0;

void solve_line(int idx, int* line, int* num, int &result) {
  // auto& line = verticals;
  // auto& num = verticals_num;
  // auto& result = v_edge_num;

  int current_edge_num = 0;
  if (idx - 1 >= 0 && line[idx] - line[idx - 1] >= 0) {
    current_edge_num += line[idx] - line[idx - 1];
  }

  if (idx + 1 < maxn && line[idx] - line[idx + 1] >= 0) {
    current_edge_num += line[idx] - line[idx + 1];
  }

  result += (current_edge_num - num[idx]);
  num[idx] = current_edge_num;
}

int main() {
  int T;
  std::cin >> T;

  rep(i, 0, T) {
    int x, y;
    std::cin >> x >> y;

    if (verticals[x] == 0) {
      v_edge_top++;
    }

    if (horizontal[y] == 0) {
      h_edge_top++;
    }

    verticals[x]++;
    horizontal[y]++;

    if (x - 1 >= 0)
      solve_line(x - 1, verticals, verticals_num, v_edge_num);
    solve_line(x, verticals, verticals_num, v_edge_num);
    if (x + 1 < maxn)
      solve_line(x + 1, verticals, verticals_num, v_edge_num);


    if (y - 1 >= 0)
      solve_line(y - 1, horizontal, horizontal_num, h_edge_num);
    solve_line(y, horizontal, horizontal_num, h_edge_num);
    if (y + 1 < maxn)
      solve_line(y + 1, horizontal, horizontal_num, h_edge_num);



    std::cout << (v_edge_num + 2 * v_edge_top) << " " << (h_edge_num + 2 * h_edge_top)
              << std::endl;
  }

  return 0;
}