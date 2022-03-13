#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
int main(){
  int a[27];
  std::string s;
  while(true){
    std::cin >> s;
    if(s == "END") break;
  }
  std::memset(a,0,sizeof(a));
  unsigned long long n = s.size();
  for(int i = 0; i < n; i++){
    if(s[i] == '_')
      a[26]++;
    else
    a[s[i] - 'A']++;
  }
  std::priority_queue<int, std::vector<int>, std::greater<int>> q;
  for(int i = 0; i<= 26; i++){
    if(a[i])
      q.push(a[i]);
  }
  unsigned long long ans = n;
  while(q.size() > 2){
    unsigned long long t, t1, t2;
    t1 = q.top(), q.pop();
    t2 = q.top(), q.pop();
    t = t1 + t2;
    ans += t;
    q.push(t);
  }
  printf("%llu %llu %.1lf\n", n * 8, ans, (double)n * 8/ ans);
  return 0;
}
