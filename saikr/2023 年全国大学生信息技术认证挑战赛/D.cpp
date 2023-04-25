#include <bits/stdc++.h>
#include <queue>
using ul = unsigned long long;

int N;
const int maxn = 1e5 + 17;

ul A[maxn], B[maxn];
ul ans[maxn];
std::priority_queue<ul> pq;
int main() {
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    std::cin >> B[i];
  }
  std::sort(A, A + N);
  std::sort(B, B + N);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      ul value = A[i] + B[j];
      if(pq.size() < N){
        pq.push(value);
      }else if(pq.top() > value){
        pq.pop();
        pq.push(value);
      }else{
        break;
      }
    }
  }
  for(int i = N-1; i >= 0; i--){
    ans[i] = pq.top();
    pq.pop();
  }
  for(int i = 0; i < N; i++){
    std::cout << ans[i] << " ";
  }
  return 0;
}
