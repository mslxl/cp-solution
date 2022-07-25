#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;

ll split(std::vector<ll>::iterator beg, std::vector<ll>::iterator end,
         int cur_k) {
  if (cur_k - 1 == 0)
    return 0;
  if (end - beg <= 1)
    return 0;
  ll max = *(end - 1);
  auto split_value = *beg + (max - *beg) / 2;
  auto split_iter = std::lower_bound(beg, end, split_value);

  ll multi = (*split_iter - *beg) * (*(end - 1) - *split_iter);
  cur_k--;

  std::cerr << *beg << "->" << *(end-1) << std::endl;
  std::cerr << "multi = " << multi << std::endl;

  if (cur_k - 1 >= 2) {
    multi += split(beg, split_iter + 2, cur_k);
    multi += split(split_iter + 2, end, cur_k);
  } else if (cur_k - 1 != 0) {
    multi += std::max(split(beg, split_iter + 1, cur_k),
                      split(split_iter + 1, end, cur_k));
  }

  return multi;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<ll> d(n);
  for (int i = 0; i < n; i++)
    std::cin >> d[i];

  std::vector<ll> prefix(n + 1);
  prefix[0] = 0;
  for (std::size_t i = 0; i < d.size(); i++)
    prefix[i+1] = prefix[i] + d[i];
  std::cout << split(prefix.begin(), prefix.end(), k);
}