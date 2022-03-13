#include<iostream>
#include<queue>

int N;
std::priority_queue<int,std::vector<int>, std::greater<int>> seq;
unsigned long long cost = 0;

#ifdef Lo
#define test if(1)
#else
#define test if(0)
#endif

int main(){
  std::ios::sync_with_stdio(false);
  std::cin >> N;
  for(int i = 0; i < N; i++){
      int input;
      std::cin >> input;
      seq.push(input);
  }
  while(seq.size() > 1){
    int n1 = seq.top();
    seq.pop();
    int n2 = seq.top();
    seq.pop();
    test std::cout << "merge " << (n1+n2) << std::endl;
    cost += (n1+n2);
    seq.push(n1+n2);
  }
  std::cout << cost;
  
  return 0;

}
