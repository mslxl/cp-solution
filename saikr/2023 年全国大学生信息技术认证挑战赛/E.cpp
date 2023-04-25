#include<bits/stdc++.h>
#include <numeric>

std::pair<int,int> v[8];
int seq[5];
int main(){
  for(int i =0; i < 8; i++){
    std::cin >> v[i].first;
    v[i].second = i+1;
  }
  std::sort(v, v+8);
  int sum = 0;
  for(int i = 3; i < 8; i++){
    sum += v[i].first;
  }
  std::cout << sum << "\n";


  int idx = 0;
  for(int i = 3; i < 8; i++){
    seq[idx++] = v[i].second;
  }
  std::sort(seq, seq+5);
  for(int i = 0; i < 5;i++){
    std::cout << seq[i] << " ";
  }
  return 0;
}
