#include<iostream>
#include<vector>

bool isPrime(int num){
  if(num <= 1) return false;
  for(int i = 2; i * i <= num; i++){
    if(num % i == 0) return false;
  }
  return true;
}
std::vector<int> primes;

bool dfs(int target,int value , int idx){
  if(target == value) return true;
  else if(value > target) return false;

  return dfs(target,target+primes[idx], idx+1) || dfs(target, target, idx+1);

}

int main(){
  const int target = 2022;
  for(int i = 0; i < target; i++ ){
    if(isPrime(i)){
      primes.push_back(i);
    }
  }
  int cnt = 0;
  for(int i = 0; i < primes.size();i++){
    std::cout << "---------------\n";
    if(dfs(target, 0, i)){
      cnt++;
    }
  }
  std::cout << cnt;

  
  return 0;
}