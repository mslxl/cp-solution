#include<bits/stdc++.h>
#ifdef Lo
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;
const int maxn = 100 + 15;
const int maxw = 10000 + 15;
int n;
int wi[maxn] = {0};
int w;

bool choice(int idx, int mass){
  int new_mass = mass + wi[idx];
  test std::cout << "mass = " << new_mass << std::endl;
  if(new_mass > w) return false;
  else if(new_mass == w) return true;
  else{
    for(int i = idx + 1; i < n; i++){
      if(choice(i, new_mass)){
         return true;
      }
    }
  }
  return false;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for(int i = 0 ; i < n; i++ ){
    std::cin >> wi[i];
  }
  std::cin >> w;
  std::sort(wi, wi + n);

  if(choice(0, 0)){
    std::cout << "Yes";
  }else{
    std::cout << "No";
  }



  return 0;
}
