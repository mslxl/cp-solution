#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i, s, e) for(int i = s; i < e; i++)

typedef long long ll;
int N, M;
std::map<std::vector<int>, int> str2id;
int id_counter = 0;


const int maxn = 1e4 + 17;

struct StrFrq{
  std::vector<int> seq;
  int times = 0;
  bool operator <(const StrFrq& rhs) const {
    if(this->times == rhs.times){
      // ordering by str
      return this->seq < rhs.seq;
    }else{
      return this->times > rhs.times;
    }
  }
};

StrFrq bucket[maxn];

int get_id_by_seq(const std::vector<int>& str){
  if(str2id.count(str)){
    return str2id[str];
  }else{
    str2id[str] = id_counter;
    return id_counter++;
  }
}

inline std::ostream& operator << (std::ostream& os, const StrFrq& rhs){
  os << rhs.times;
  for(const auto& item : rhs.seq){
    std::cout << ' ' << item;
  }
  return os;
}


int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;
  std::cin.get();
  std::string line;
  rep(i, 0, N){
    std::vector<int> seq(M);
    rep(j,0,M) std::cin >> seq[j];
    StrFrq& frq = bucket[get_id_by_seq(seq)];
    if(frq.times == 0){
      frq.seq = seq;
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
