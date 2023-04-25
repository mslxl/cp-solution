#include <bits/stdc++.h>
#define int long long
struct Word {
  std::string w;
  int weight;
  bool operator<(const Word& rhs) const {
    if (this->weight == rhs.weight) {
      return this->w < rhs.w;
    }
    return this->weight > rhs.weight;
  }
};

using ll = long long;

ll f(int m, int i, int s){
  return (m - i + 1) * s;
}

void solve() {
  int line, m;
  std::cin >> line >> m;
  std::vector<Word> seq(line);
  for (int i = 0; i < line; i++) {
    std::cin >> seq[i].w >> seq[i].weight;
  }
  std::sort(seq.begin(), seq.end());

  ll value = 0;
  for (int i = 0; i < m; i++) {
    value += f(m, i+1, seq[i].weight);
  }
  std::cout << value;


  for (int i = 0; i < m; i++) {
    std::cout << " " << seq[i].w;
  }

  std::cout << std::endl;
}

#undef int
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}