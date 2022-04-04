#include<bits/stdc++.h>

typedef unsigned long long ll;

int main(){
  ll timestamp;
  std::cin >> timestamp;
  ll ms = timestamp;
  ll s = ms / 1000;

  ll ss = s % 60;
  ll m = s / 60;

  ll mm = m % 60;

  ll h = m / 60;
  ll hh = h % 24;

  printf("%02lld:%02lld:%02lld", hh,mm,ss);

  return 0;
}
