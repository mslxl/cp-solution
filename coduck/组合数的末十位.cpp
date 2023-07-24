#include<bits/stdc++.h>

const int maxsize = 3e4 + 17;
const int maxn = 20 + 17;

int a[maxsize], b[maxn];

int n, r;

void solve_factor(int n){
  for(int m = 2; m * m <= n; m++){
    while(n % m == 0 && n != 0){
      n /= m;
      a[m]++;
    }
  }
  a[n]++;
}

void reduce(int n){
  for(int m = 2; m <= n; m++){
    while(n % m == 0 && n != 0){
      n /= m;
      a[m]--;
    }
  }
  a[n]--;
}

void multi(int d){
  int inc = 0;
  for(int i = 1; i <= maxn; i++){
    b[i] = b[i] * d + inc;
    inc = b[i] / 10;
    b[i] %= 10;
  }
}


int main(){
  std::cin >> n >> r;
  for(int i = n-r+1; i <= n; i++){
    solve_factor(i);
  }
  for(int j = r; j > 1; j--){
    reduce(j);
  }

  b[1] = 1;
  for(int i = 2; i <= 29999; i++){
    while(a[i] > 0){
      multi(i);
      a[i]--;
    }
  }

  for(int i = 10; i >= 1; i--){
    std::cout << b[i];
  }



  return 0;
}