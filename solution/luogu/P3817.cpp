#include <iostream>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;
int n, x;
std::vector<ll> boxs;
ll eat = 0;
ll size = 0;

inline ll left_sum(ll node){
  if(node == 0) return boxs[node];
  return boxs[node-1] + boxs[node];
}
inline ll right_sum(ll node){
  if(node == size-1) return boxs[node];
  return boxs[node+1] + boxs[node];
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin >> n >> x;
  for(int i = 0; i < n; i++){
    ll input;
    std::cin >> input;
    if(input > x){
      eat += (input - x);
      input = x;
    }
    boxs.push_back(input);
  }
  size = boxs.size();

  for(ll i = 0; i < n;){
    if(left_sum(i) > x){
      ll value = (left_sum(i) - x);
      boxs[i] -= value;
      eat+=value;
    }else if(right_sum(i) > x){
      ll value = (right_sum(i) - x);
      boxs[i+1] -= value;
      eat+=value;
    }else{
      i++;
    }
  }
  std::cout << eat;
  return 0;
}
