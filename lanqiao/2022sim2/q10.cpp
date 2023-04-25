#include<iostream>
#include<string>
#include<vector>

int main(){
  using ll = unsigned long long;
  int n;
  std::cin >> n;
  std::vector<ll> seq(n);
  for(int i = 0; i < n; i++) std::cin >> seq[i];
  ll cost = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(seq[j-1] > seq[j]){
        cost += seq[j-1];
        std::swap(seq[j-1], seq[j]);
      }
    }
  }
  std::cout << cost;

  return 0;
}