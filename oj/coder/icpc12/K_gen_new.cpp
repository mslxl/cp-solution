#include<bits/stdc++.h>

const int max = 1e3;

int a[] = {2,3,17,19};
int b[] = {5,7,11,13};

std::map<int, int> dfsa_num;
std::map<int, int> dfsb_num;

void dfsa(int cur_coin, int num){
  if(cur_coin > max){
    return;
  }
  for(int i = 0; i < 4; i++){
    int t = cur_coin + a[i];
    if(dfsa_num[t] == 0 || dfsa_num[t] > num){
      dfsa_num[t] = num;
      // printf("%d ", t);
      dfsa(t, num + 1);
    }
  }
}

void dfsb(int cur_coin, int num){
  if(cur_coin > max){
    return;
  }
  for(int i = 0; i < 4; i++){
    int t = cur_coin + b[i];
    if(dfsb_num[t] == 0 ||dfsb_num[t] > num){
      dfsb_num[t] = num;
      // printf("%d ", t);
      dfsb(t, num + 1);
    }
  }
}



int main(){
  dfsa(0,1);
  dfsb(0,1);
  std::ofstream file("array.txt");
  for(int i = 0; i < max; i++){
    std::cout << i << "\t";
    file << "{" << i << ",";
    if(dfsa_num[i] == 0 && dfsb_num[i] == 0){
      file << "-1";
      std::cout << "-1";
    }else if(dfsa_num[i] < dfsb_num[i]){
      file << 'A' - '0';
      std::cout << "A";
    }else if(dfsa_num[i] > dfsb_num[i]){
      if(i > 500){
        assert(false);
      }
      file << 'B' - '0';
      std::cout << "B";
    }else if(dfsa_num[i] == dfsb_num[i]){
      file << 3;
      if(i > 500){
        assert(false);
      }
      std::cout << "both";
    }
    file<< "},";
    std::cout << std::endl;
  }
  file.flush();
    file.close();
}