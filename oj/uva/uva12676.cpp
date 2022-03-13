#include<bits/stdc++.h>
#ifdef Lo
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;

ll solve(std::vector<ll>& seq){
  std::map<ll, ll, std::greater<ll>> bucket;
  ll max_depth = std::accumulate(seq.cbegin(), seq.cend(), 0, [](const ll l, const ll r)->ll {
    return std::max(r,l);
  });
  std::for_each(seq.begin(), seq.end(), [&bucket](const ll item){
    bucket[item]++;
  });

  ll weight = 1;
  std::vector<ll> nodes[max_depth + 1];

  for(ll i = max_depth; i > 0; i--){
    for(ll j = 0; j < bucket[i]; j++){
      nodes[i].push_back(weight);
    }
    std::sort(nodes[i].begin(), nodes[i].end(), std::greater<ll>());
    weight = nodes[i][0];

    for(ll j = 0; j < nodes[i].size(); j+=2){
      nodes[i-1].push_back(nodes[i][j] + nodes[i][j+1]);
    }
  }

  return nodes[0][0];
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T;
  while(std::cin >> T){
    std::vector<ll> seq(T);
    for(int i = 0; i < T; i++){
      std::cin >> seq[i];
    }
    std::cout << solve(seq) << std::endl;
  }
  return 0;
}
