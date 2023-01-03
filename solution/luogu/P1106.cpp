#include<iostream>
#include<string>
#include<algorithm>
std::string N;
std::string result("");
int k;

int find_min(int start, int end){
  char min = N[start];
  int min_pos = start;
  end = std::min(end, static_cast<int>(N.size()));

  for(int i = start + 1; i < end; i++){
    if(N[i] < min){
      min = N[i];
      min_pos = i;
    }
  }
  return min_pos;
}


int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> N >> k;
  int select_num = N.size() - k;
  int left = 0;
  while(select_num != 0){
     int pos = find_min(left, N.size() - select_num + 1);
     result.push_back(N[pos]);
     left = pos + 1;
     select_num--;
  }
  std::cout << std::stoi(result);
  return 0;
}
