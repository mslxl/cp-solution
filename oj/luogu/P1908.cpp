#include <bits/stdc++.h>
typedef long long ll;

#ifdef Lo
#define test if (1)
#else
#define test if (0)
#endif

constexpr int maxn = 5 * 1e5 + 10;

int n;
int seq[maxn];
int tmp[maxn];

ll count_rev(int l, int r) {
  if (r == l)
    return 0;

  test std::cout << "merge [" << l << " ," << r << "]" << std::endl;

  ll ans = 0;
  int mid = l + (r - l) / 2;

  ans += count_rev(l, mid);
  ans += count_rev(mid + 1, r);

  for (int i = l, j = mid + 1, idx = l; idx <= r;) {
    if ((i <= mid && seq[i] <= seq[j]) || j > r) {
      test std::cout << "get " << seq[i] << " from left" << std::endl;
      tmp[idx] = seq[i];
      i++, idx++;
    } else {
      test std::cout << "get " << seq[j] << " from right" << std::endl;
      ans += (mid - i + 1);
      tmp[idx] = seq[j];
      j++, idx++;
    }
  }
  std::memcpy(seq + l, tmp + l, (r - l + 1) * sizeof(int));

  test {
    std::cout << "after merge [" << l << ',' << mid << "] and [" << mid + 1
              << ',' << r << "], now seq: [" << seq[0];
    for (int i = 1; i < n; i++) {
      std::cout << " ," << seq[i];
    }
    std::cout << "]" << std::endl;
  }

  return ans;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> seq[i];

  std::cout << count_rev(0, n - 1);

  return 0;
}
