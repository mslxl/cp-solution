#include<iostream>
#include<queue>
std::priority_queue<int, std::vector<int>, std::greater<int> > queue;
int main(){
  int n;
  std::cin >> n;
  int input;
  while(n--){
    std::cin >> input;
    queue.push(input);
  }
  int consumption = 0;
  while(queue.size() != 1){
    int x = queue.top();
    queue.pop();
    int y = queue.top();
    queue.pop();
    int con = x + y;
    queue.push(con);
    consumption += con;
  }
  std::cout << consumption ;
  return 0;
}
