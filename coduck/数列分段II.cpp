#include<bits/stdc++.h>
#include <numeric>


int N,M;
std::vector<int> seq;
std::vector<int> prefix;
int sum(int l, int r){
  return prefix[r] - prefix[l-1];
}

bool check(int target_sum, int target_seg){
  int cnt = 1;
  for(int i = 1; i < prefix.size();){
    bool seg = false;
    for(int j = i; j < prefix.size(); ){

      if(sum(i, j) <= target_sum){
        j++;
      }else{
        seg = true;
        i = j;
        cnt++;
        break;
      }
    }
    if(!seg){
      break;
    }
  }
  return cnt <= target_seg;
}


int main(){
  std::cin >> N >> M;
  seq.resize(N+1);
  prefix.resize(N+1);
  std::cin >> seq[1];
  prefix[1] = seq[1];
  for(int i = 2; i <= N;i++){
    std::cin >> seq[i];
    prefix[i] = prefix[i-1] + seq[i];
  }


  int max = std::accumulate(seq.begin(), seq.end(), 0);
  int min = std::accumulate(seq.begin(), seq.end(), 0, [](const int l, const int r){
    return std::max(l,r);
  });


  int l = min, r = max;
  while(l <= r){
    int mid = l + (r-l)/2;
    if (check(mid, M)) {
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  std::cout << l;

  return 0;

}