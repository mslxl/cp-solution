class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    std::vector<int> f(amount + 1);
    std::fill(f.begin(), f.end(), 0x3f3f3f);
    f[0] = 0;
    for (int i = 1; i < f.size(); i++) {
      for (auto c : coins) {
        if (i - c < 0)
          continue;
        f[i] = std::min(f[i - c] + 1, f[i]);
      }
    }
    if (f[amount] >= 0x3f3f3f) {
      return -1;
    }
    return f[amount];
  }
};
