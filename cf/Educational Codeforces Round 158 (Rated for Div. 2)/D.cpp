#include<bits/stdc++.h>
template<class R, class A> R mmax(R x, A y){ return std::max(x, (R) y); } template<class R, class A, class... AS> R mmax(R x, A xx, AS... xxs){ return std::max(x, mmax((R)xx, xxs...));  }
template<class R, class A> R mmin(R x, A y){ return std::min(x, (R) y); } template<class R, class A, class... AS> R mmin(R x, A xx, AS... xxs){ return std::min(x, mmin((R)xx, xxs...));  }

int main(){
  #define int long long
  int n;
  std::cin >> n;
  std::vector<int> s(n+2);
  
  for(int i = 1; i <= n; i++){
    std::cin >> s[i];
  }

  std::vector<int> pre(s.size()), suf(s.size());
  for(int i = 1; i <= n; i++){
    pre[i] = n - i + s[i];
    suf[i] = i - 1 + s[i]; 
  }
  for(int i = 1; i <= n; i++) pre[i] = std::max(pre[i], pre[i-1]);
  for(int i = n; i >= 1; i--) suf[i] = std::max(suf[i], suf[i+1]);
  int atk = 0x3f3f3f3f;
  
  for(int i = 1; i <= n; i++){
    atk = mmin(
      atk,
      mmax(
        pre[i-1],
        suf[i+1],
        s[i]
      )
    );
  }
  std::cout << atk;
  
}