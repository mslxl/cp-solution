#include<bits/stdc++.h>
#include <csignal>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;
struct Rail{
  std::string content;
  int pos;
  char drop(){
    return content[pos++];
  }
  bool empty(){
    return pos == content.size();
  }
};

std::istream& operator >> (std::istream& is, Rail& rhs){
  is >> rhs.content;
  return is;
}

int N, M, S;
std::vector<char> line;
std::stack<char> basket;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> N >> M >> S;
  std::vector<Rail> rails(N+1);

  for(int i = 1;  i <= N; i++){
    std::cin >> rails[i];
  }

  int button;
  while(std::cin >> button && button != -1){
    test std::cout << "btn " << button << " :";
    if(button == 0 && !basket.empty()){
      line.push_back(basket.top());
      test std::cout << "get " << basket.top() << " from basket" << std::endl;
      basket.pop();
    }else if(!rails[button].empty()){
      if(basket.size() == S){
        line.push_back(basket.top());
        test std::cout << "\tget " << basket.top() << " from basket" << std::endl;
        basket.pop();
      }
      basket.push(rails[button].drop());
      test std::cout << "drop " << basket.top() << " from " << button << ", current size of basket " << basket.size() << std::endl;
    }else{
      test std::cout << std::endl;
    }
  }
  for(const auto& c: line){
    std::cout << c;
  }


  return 0;
}
