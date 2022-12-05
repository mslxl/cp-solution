#include <bits/stdc++.h>
const int maxn = 1000 + 17;
int f[maxn];
int main() {
  int N, V;
  std::cin >> N >> V;
  std::vector<int> v(N + 1), w(N + 1), s(N+1);

  for (int i = 1; i <= N; i++) std::cin >> v[i] >> w[i] >> s[i];

  for (int i = 1; i <= N; i++)
    for (int j = V; j >= v[i]; j--)
      for(int k = 1; k <= s[i] && k * v[i] <= j; k++)
        f[j] = std::max(f[j], f[j - k* v[i]] + k*w[i]);
  std::cout << f[V];
  return 0;
}