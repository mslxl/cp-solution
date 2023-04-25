#include <algorithm>
#include <iostream>
typedef unsigned long long ll;
const int maxw = 10e3 + 200;
const ll modd = 10e9 + 7;
int N, M;
int w[maxw];
ll mm[maxw] = {0};

void buy(int no, bool half, ll mess) {
  if (no >= N)
    return;
  int cur_mess = w[no] + mess;
  if (half) {
    cur_mess = w[no] / 2 + mess;
  }
  if (cur_mess > M)
    return;
  mm[cur_mess]++;
  for (int i = no + 1; i < N; i++) {
    buy(i, true, cur_mess);
    buy(i, false, cur_mess);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> N >> M;
  if (N == 0) {
    std::cout << 0;
  } else {
    for (int i = 0; i < N; i++) {
      std::cin >> w[i];
    }
    std::sort(w, w + N);
    for (int i = 0; i < N; i++) {
      buy(i, true, 0);
      buy(i, false, 0);
    }
    for (int i = 1; i <= M; i++) {
      std::cout << mm[i] % modd << ' ';
    }
  }
  return 0;
}
