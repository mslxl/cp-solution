#include <bits/stdc++.h>
#include <limits>

int N;
std::vector<int> seq;

int max_v = std::numeric_limits<int>::min(),
    min_v = std::numeric_limits<int>::max();

int main() {
  std::cin >> N;
  seq.resize(N + 1);

  for (int i = 0; i < N; i++){
    std::cin >> seq[i];

    max_v = std::max(max_v, seq[i]);
    min_v = std::min(min_v, seq[i]);
  }


  do{
    double L = 0, R = std::numeric_limits<double>::max();
    double ans = 0;
    while(std::abs(L-R) > 0.001){
      double mid = (L+R) / 2;
      
    }
  }while(0);

}