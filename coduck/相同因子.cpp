#include <bits/stdc++.h>

bool is_prime(int x){
  if(x == 1) return false;
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0) return false;
  }
  return true;
}

int main() {
  #define int long long
  int a, b;
  std::cin >> a >> b;

  if(a == 1 || b == 1){
    std::cout << "NO";
    return 0;
  }

  int r = std::__gcd(a, b);
  if(r > 1 && (r != std::min(a, b) || !is_prime(std::min(a, b)))){
    std::cout << "YES";
  }else{
    std::cout << "NO";
  }

  return 0;
}