#include <bits/stdc++.h>
#include <stack>

const int N = 1e6 + 17;

int cnt = 0;
std::stack<int> num;
std::stack<char> op;
std::string s;
std::map<char, int> rk;
int n;

struct node{
  char num;
  int ls, rs;
  node(){}
  node(char s):num(s){}
  node(char s, int l, int r): num(s), ls(l), rs(r){}
} tr[N];


void create(){
  int y = num.top();
  num.pop();
  int x = num.top();
  num.pop();

  tr[++cnt] = node(op.top(), x, y);
  op.pop();
  num.push(cnt);
}

void build(){
  for(int i = 1; i <= n; i++){
    if(s[i] == '('){
      op.push(s[i]);
    }else if(s[i] == ')'){
      while(op.top() != '(') create(); // 给括号内的建树
      op.pop(); //左括号出栈
    }else if(s[i] == '&' || s[i] == '|'){
      while(!op.empty() && rk[op.top()] >= rk[s[i]])
        create();
      op.push(s[i]);
    }else{
      tr[++cnt] = node(s[i]);
      num.push(cnt);
    }
  }
  while(!op.empty()) create();
}

int cnt1, cnt2;
int dfs(int pos){
  if(tr[pos].num == '0') return 0;
  if(tr[pos].num == '1') return 1;
  if(tr[pos].num == '&'){
    if(dfs(tr[pos].ls) == 0){
      cnt1++;
      return 0;
    }
    return dfs(tr[pos].rs);
  }

  if(dfs(tr[pos].ls) == 1){
    cnt2++;
    return 1;
  }
  return dfs(tr[pos].rs);
}

int main(){
  std::cin >> s;
  n = s.size();
  s = " " + s;
  rk['|'] = 1;
  rk['&'] = 2;
  build();
  int value = dfs(cnt);
  std::cout << value << "\n" << cnt1 << " " << cnt2;
}