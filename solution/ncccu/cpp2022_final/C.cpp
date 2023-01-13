#include <algorithm>
#include<bits/stdc++.h>
#include <limits>
int M, S, C;
std::vector<int> seq;
bool lid[217];

int get_lid_num(){
  int ans = 0;
  for(int i = 0; i < 217;i++){
    if(lid[i] == false && lid[i-1]==true){
      ans++;
    }
  }
  return ans;
}

int main(){
  std::cin >> M >> S >> C;
  for(int i = 0; i < C; i++){
    int v;
    std::cin >> v;
    seq.push_back(v);
    lid[v] = true;
  }
  std::sort(seq.begin(), seq.end());
  std::vector<int> diff(C);

  for(int i = 1; i < C; i++){
    diff[i] = seq[i] - seq[i-1];
  }

  int lid_num = get_lid_num();
  int diff_limit = 2;
  while(lid_num > M){
    int min_diff_pos = 1;
    int min_diff = std::numeric_limits<int>::max();
    for(int i = 0; i < diff.size(); i++){
      if(diff[i] >= diff_limit && diff[i] < min_diff){
        min_diff = diff[i];
        min_diff_pos=i;
      }
    }
	diff[min_diff_pos] = 1;
	//std::cerr << "fill " << seq[min_diff_pos-1] << "->" << seq[min_diff_pos] << std::endl;
    for(int i = seq[min_diff_pos-1]; i < seq[min_diff_pos];i++){
      lid[i]=true;
    }
    diff_limit = min_diff;
    lid_num = get_lid_num();
  }
  
  int ans=0;
  for(int i = 1; i <=S;i++ ){
    if(lid[i]) ans++;
  }
  std::cout << ans;
  
  return 0;
}
