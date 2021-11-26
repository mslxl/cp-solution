#include<iostream>
#include<vector>

typedef unsigned long long ll;

const int maxbit = 1e10;
struct Num{
  short bits[maxbit] = {-1};
  Num(ll n){
    for(ll idx = 0; n != 0; idx++, n/=10){
      bits[idx] = n % 10;
    }
  }
  Num operator+(const Num& rhs) const {
    short up_grade = 0;
    for(ll idx = 0; rhs.bits[idx] != -1 || this->bits[idx] != -1; idx++){


    }
  }
};


std::vector<ll> fibs;
ll N;
int main(){
  std::ios::sync_with_stdio(false);
  std::cin >> N;
  fibs.push_back(-1);
  fibs.push_back(1);
  fibs.push_back(2);
  for(ll idx = 3; idx <= N; idx++){
    fibs.push_back(fibs[idx-2] + fibs[idx-1]);
  }
  std::cout << fibs[N];
  return 0;
}

