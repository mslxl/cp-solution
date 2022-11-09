#include <bits/stdc++.h>

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> seq(n + 1);
  std::vector<ll> prefix_sum(n + 1, 0), prefix_xor(n + 1, 0);

  std::map<ll, int> odd, even;
  std::map<ll, int> last;

  for (int i = 1; i <= n; i++) {
    std::cin >> seq[i];
    prefix_sum[i] = prefix_sum[i - 1] + seq[i];
    prefix_xor[i] = prefix_xor[i - 1] ^ seq[i];

    if (i % 2 == 0) {
      // even
      if(odd.count(prefix_xor[i])){
        last[i] = odd[prefix_xor[i]];
      }
      even[prefix_xor[i]] = i;
    }else{
      // odd
      if(even.count(prefix_xor[i])){
        last[i] = even[prefix_xor[i]];
      }
      odd[prefix_xor[i]] = i;
    }
  }

  while(k--){
    int l,r;
    std::cin >> l >> r;
    if(prefix_xor[r] != prefix_xor[l-1]){
      std::cout << "-1\n";
      continue;
    }else if(prefix_sum[r] == prefix_sum[l-1]){
      std::cout << "0\n";
      continue;
    }else if((r - l + 1) % 2 != 0){
      std::cout << "1\n";
      continue;
    }else if(seq[l]== 0 || seq[r] == 0){
      std::cout << "1\n";
      continue;
    }else if(last[r] > l){
      std::cout << "2\n";
      continue;
    }else {
      std::cout << "-1\n";
      continue;
    }
  }
}