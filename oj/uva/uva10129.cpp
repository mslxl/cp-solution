#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
int T;

int G[26][26];
bool has_node[26] = {false};

void read_graph(){
  memset(G, 0, sizeof(G));
  memset(has_node, false, sizeof(has_node));
  int n;
  std::cin >> n;
  std::string wd;
  while(n--){
    std::cin >> wd;
    char fst = wd[0];
    char tail = wd[wd.size()-1];
    G[fst-'a'][tail-'a'] ++;
    has_node[fst-'a'] = true;
    has_node[tail-'a'] = true;
  }
};

bool is_scc_from(char rec){
  bool has_node_t[26] = {false};
  memcpy(has_node_t, has_node, sizeof(has_node));
  std::queue<int> queue;
  queue.push(rec - 'a');
  while(!queue.empty()){
    int cur = queue.front();
    has_node_t[cur] = false;
    queue.pop();
    for(int i = 0; i < 26; i++){
      if(has_node_t[i] && G[cur][i] != 0){
        queue.push(i);
      }
    }
  }
  for(int idx = 0; idx < 26; idx++){
    if(has_node_t[idx]) return false;
  }
  return true;
}

bool is_scc(){
  for(char c = 'a'; c <= 'z'; c++){
      if(is_scc_from(c)) return true;
  }
  return false;
}

bool solve(){
  if(!is_scc()) return false;
  bool has_start = false, has_end = false;
  int start_pt[26] = {0};
  int end_pt[26] = {0};
  for(int u = 0; u < 26; u++){
    for(int v = 0; v < 26; v++){
      if(G[u][v] != 0){
        start_pt[u] += G[u][v];
        end_pt[v] += G[u][v];
      }
    }
  }
  int neq = 0;
  for(int idx = 0; idx < 26; idx++){
    if(start_pt[idx] != end_pt[idx]){
      neq++;
      if(start_pt[idx] - end_pt[idx] == 1 && !has_start){
        has_start = true;
      }else if(start_pt[idx] - end_pt[idx] == -1 && !has_end){
        has_end = true;
      }else{
        return false;
      }
    }
  }
  return neq == 2 || neq == 0;
}

int main(){
  std::cin >> T;
  while(T--){
    read_graph();
    std::cout << (solve()? "Ordering is possible." : "The door cannot be opened.")
              << std::endl;
  }
}
