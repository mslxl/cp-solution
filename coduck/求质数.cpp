#include<bits/stdc++.h>
#include <unordered_set>

std::set<int> prime;
std::unordered_set<int> composite;

void eular(int n){
  composite.insert(1);
  for(int i = 2; i <= n; i++){
    if(!composite.count(i)) prime.insert(i);

    for(auto p: prime){
      if(p * i > n) break;
      composite.insert(p * i);
      if(i % p == 0) break;
    }
  }

}


int main(){
  int n;
  std::cin >> n; 
  eular(n);
  for(auto p: prime){
    std::cout << p << " ";
  }
}