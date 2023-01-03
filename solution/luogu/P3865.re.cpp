#include<bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int maxn  = 1e5  + 17;

int table[maxn][21];

// index 0 will still be the position 0 in table
void st_build(const std::vector<int>& data){

	for(std::size_t i = 1; i <= data.size(); i++){
		table[i][0] = data[i-1];
	}
	int k = std::log2(data.size());
	for(std::size_t j = 1; j <= k; j++){
		for(std::size_t i = 1; i <= data.size() - (1 << j) + 1 + 1; i++){
			table[i][j] = std::max(table[i][j-1], table[i + (1 << (j - 1))][j-1]);
		}
	}

}

// left is start with 0!!!
int st_query(int left,int right){
  left++;
  right++;
	int k = std::log2(right - left + 1);
	return std::max(table[left][k], table[right-(1<<k)+1][k]);
}

template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type read(T &value) {
  value = 0;
  char ch = getchar();
  bool flag = false;
  while (!std::isdigit(ch)) {
    if (ch == '-')
      flag = true;
    ch = getchar();
  }
  while (std::isdigit(ch)) {
    value = value * 10 + (ch - '0');
    ch = getchar();
  }
  if (flag)
    value *= -1;
}

template <typename T, typename... A> void read(T &value, A &..._t) {
  read(value);
  read(_t...);
}

int main(){
  int n,m;
  read(n,m);
  std::vector<int> seq(n+1);
  seq[0] = 0;
  for(int i = 1; i <= n; i++) read(seq[i]);
  st_build(seq);
  for(int i = 0; i < m; i++){
    int l,r;
    read(l,r);
    std::cout << st_query(l,r) << "\n";
  }

	return 0;
}