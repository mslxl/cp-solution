// Problem: Gone Fishing
// Contest: POJ - East Central North America 1999
// URL: http://poj.org/problem?id=1042
// Memory Limit: 32 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// clang-format off
#include <iostream>
#include <string>
int n,h;
const int maxn = 25+17;
int f[maxn], t[maxn], d[maxn], time_split[maxn] ,use_time;
double expect_time_per_fish[maxn];
bool reached[maxn];

void produce_expect_time(){
  for(int i = 1; i <= n; i++) {
    if(!reached[i]){
        for(int j = 1; j <= n; j++){
          if(reached[j]){
            expect_time_per_fish[i] = t[j] + 1.0 / f[i];
          }
          
        }
    }
    
  }
}

int main(){
  while(true){
    std::cin >> n;
    use_time = 0;
    if(n==0){
      return 0;
    }
    std::cin >> h;
    h *= 60;
    h /= 5;
    for(int i = 1; i <= n; i++) std::cin >> f[i];
    for(int i = 1; i <= n; i++) std::cin >> d[i];
    for(int i = 0; i <= n; i++) reached[i] = false;
    reached[0] = reached[1] = true;
    for(int i = 1; i < n; i++) std::cin >> t[i];
 
    int maxpos = 1;
    for(int i = 1; i <= h; i++){
      
    }
    
  }
  
  return 0;
}