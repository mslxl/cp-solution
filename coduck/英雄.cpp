#include<bits/stdc++.h>


const int maxn = 20 + 17;
int N;
struct Monster{
  int hp;
  int dps;

  bool operator<(const Monster& rhs) const {
    return dps * rhs.hp >  rhs.dps * hp;
  }
} mon[maxn];

int main(){
  std::cin >> N;
  for(int i = 1; i <= N; i++){
    std::cin >> mon[i].dps >> mon[i].hp;
  }
  std::sort(mon + 1, mon + 1 + N);

  int dps = 0;
  for(int i = 1; i <= N; i++){
    dps += mon[i].dps;
  }

  int hurt = 0;
  for(int i = 1; i <= N; i++){
    hurt += mon[i].hp * dps;
    dps -= mon[i].dps;
  }

  std::cout << hurt;



  return 0;
}