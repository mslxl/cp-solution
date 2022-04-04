#include <algorithm>
#include<bits/stdc++.h>
#include <numeric>
#ifdef Lo
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;
const int maxn = 20 + 1;
int n,k;
ll seq[maxn];

std::string tmp = "";

auto sum_func = [](ll l ,ll r){
  test std::cout << "+" << r << std::endl;
  return l + r;
};

bool is_prime(ll n){
  //TODO: optimize
  for(ll i = 2; i * i < n; i++){
    if(n % i == 0) return false;
  }
  return true;
}

void prod(int idx, std::function<void(ll)> func, int cur = 1, ll sum = 0){
  std::string level = tmp;
  for(int i = idx + 1; i < n; i++){
    if(cur == 3){
      test{
        tmp+= "+"  + std::to_string(seq[i]);
      }
      test std::cout << tmp << std::endl;
      func(sum + seq[i]);
      test tmp = level;
    }else{
      test{
        tmp+= "+"  + std::to_string(seq[i]);
      }
      prod(idx + 1, func, cur+1, sum + seq[i]);
      test tmp = level;
    }
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  // Try try :)
  std::cin >> n >> k;
  for(int i = 0; i < n; i++){
    std::cin >> seq[i];
  }

  ll ans = 0;
  prod(0, [&ans](ll ret){
      test std::cout << "sum = " << ret << std::endl;
      if(is_prime(ret)){
          test std::cout << "is prime" << std::endl;
          ans++;
      }
  });

  std::cout << ans;
  return 0;
}
