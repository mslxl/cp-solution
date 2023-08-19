#include<bits/stdc++.h>

int main(){
  int n;
  std::cin >> n;
  std::queue<int> que;
  std::stack<int> st;

  int op, x;
  while(n--){
    std::cin >> op;
    switch(op){
      case 1:
        std::cin >> x;
        st.push(x);
        break;
      case 2:
        std::cin >> x;
        que.push(x);
        break;
      case 3:
        if(!st.empty()) st.pop();
        break;
      case 4:
        if(!que.empty()) que.pop();
        break;
      case 5:
        if(st.empty()){
          std::cout << "Stack is empty";
        }else{
          auto cp = st;
          while(!cp.empty()){
            std::cout << cp.top() << " ";
            cp.pop();
          }
        }
        std::cout << "\n";
        break;
      case 6:
        if(que.empty()){
          std::cout << "Queue is empty";
        }else{
          auto cp = que;
          while(!cp.empty()){
            std::cout << cp.front() << " ";
            cp.pop();
          }
        }
        std::cout << "\n";
        break;
    }
  }
  return 0;
}