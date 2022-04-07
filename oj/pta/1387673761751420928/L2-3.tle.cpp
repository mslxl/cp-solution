#include<bits/stdc++.h>
#include <thread>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i, s, e) for(int i = s; i < e; i++)

typedef long long ll;
int N, M;
std::map<std::string, int> str2id;
int id_counter = 0;


bool str_lt(const std::string& lhs, const std::string& rhs){
  int lhs_idx = 0, rhs_idx = 0;
  int lhs_space_idx = 0, rhs_space_idx;
  while((lhs_space_idx = lhs.find(' ', lhs_idx)) != -1){
    rhs_space_idx = rhs.find(' ', rhs_idx);
    int l = std::stoi(lhs.substr(lhs_idx, lhs_space_idx - lhs_idx));
    int r = std::stoi(rhs.substr(rhs_idx, rhs_space_idx - rhs_idx));
    test std::cout << "Compare " << l << " and " << r << std::endl;
    lhs_idx = lhs_space_idx + 1;
    rhs_idx = rhs_space_idx + 1;
    if(l != r){
      return l < r;
    }
  } 
  return false;
}


const int maxn = 1e4 + 17;
struct StrFrq{
  std::string str;
  int times = 0;
  bool operator <(const StrFrq& rhs) const {
    if(this->times == rhs.times){
      // ordering by str
      return str_lt(this->str, rhs.str);
    }else{
      return this->times > rhs.times;
    }
  }
};

StrFrq bucket[maxn];

int get_id_by_string(const std::string& str){
  if(str2id.count(str)){
    return str2id[str];
  }else{
    str2id[str] = id_counter;
    return id_counter++;
  }
}

inline std::ostream& operator << (std::ostream& os, const StrFrq& rhs){
  return os << rhs.times << ' ' << rhs.str;
}


int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;
  std::cin.get();
  std::string line;
  rep(i, 0, N){
    std::getline(std::cin, line);
    StrFrq& frq = bucket[get_id_by_string(line)];
    if(frq.times == 0){
      frq.str = line;
    }
    frq.times++;
  }
  std::sort(bucket, bucket + id_counter);

  std::cout << id_counter;
  rep(i,0, id_counter){
    std::cout << std::endl << bucket[i];
  }
  return 0;
}
