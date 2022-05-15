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
using ll = long long;
#define rep(i, s, e) for (int i = s; i < e; i++)

const int maxn = 50 + 17;

bool occupy[maxn];
void solve(std::string& A, std::string& B) {
  std::fill_n(occupy, maxn, false);
  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());
  if(A == B){
    std::cout << "0" << std::endl;
    return;
  }

  int op_num = 0;
  int nearest = 0, min = INT32_MAX;
  rep(i, 0, B.size()){
    rep(j, 0, A.size()){
      if(occupy[j]) continue;
      if((B[i] - A[j] + 26) % 26 < min){
        min = (B[i] - A[j] + 26) % 26;
        nearest = j;
      }
    }
    op_num += min;

    min = INT32_MAX;
    occupy[nearest] = true;
    nearest = 0;
  }

  std::cout << op_num << std::endl;
}

int main() {
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  std::string x, y;
  while (std::cin >> x >> y) {
    solve(x, y);
  }

  return 0;
}