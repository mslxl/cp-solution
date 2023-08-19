#include<bits/stdc++.h>

int main(){
  int N; 
  while(std::cin >> N && N != 0){
    std::queue<int> s;
    for(int i = 1; i <= N; i++){
      int v;
      std::cin >> v;
      s.push(v);
    }
    std::stack<int> st;
    for(int i = 1; i <= N; i++){
      st.push(i);
      while(!st.empty() && st.top() == s.front()){
        st.pop();
        s.pop();
      }
    }

    if(s.empty()){
      std::cout << "Yes\n";
    }else{
      std::cout << "No\n";
    }
  }
  return 0;
}