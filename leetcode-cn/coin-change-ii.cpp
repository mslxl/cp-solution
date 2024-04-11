class Solution {
public:
  int change(int amount, vector<int> &coins) {
    std::vector<int> f(amount + 1, 0);
    f[0] = 1;
    for (auto c : coins) {
      for (int i = c; i <= amount; i++) {
        f[i] += f[i - c];
      }
    }
    return f[amount];
  }
};
