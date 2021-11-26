#include<iostream>
#include<algorithm>
int n;
struct ppl{
  double wait;
  int idx;
  bool operator<(const ppl& rhs) const {
    return this->wait < rhs.wait;
  }
};
ppl *queue;
long long sum;
int main(){
  //std::ios::sync_with_stdio(false);
  std::cin >> n;
  queue = new ppl[n];
  for(int i = 0;i < n; i++){
    queue[i].idx = i+1;
    std::cin >> queue[i].wait;
  }
  std::sort(queue,queue+n);
  for(int i = 0; i < n; i++){
    std::cout << queue[i].idx;
    if(i != n - 1) std::cout << " ";
    sum+= queue[i].wait * (n - i - 1);
  }
  std::cout << std::endl;
  printf("%.2lf", 1.0 * sum / n);
}
