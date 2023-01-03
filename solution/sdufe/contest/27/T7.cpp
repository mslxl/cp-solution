#include<bits/stdc++.h>
#include <utility>
#ifdef Lo
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;
const int maxn = 100 + 100;
const int maxm = 100 + 100;

int m,n;

char G[maxm][maxn];
bool vis[maxm][maxn];

const int offset[][2] = {
         {-1,-1}, {-1,0}, {-1, 1},
         {0,-1}, {0, 1},
         {1,-1}, {1,0}, {1, 1},
};

// floodfill
void bfs(int x,int y){
  std::queue<std::pair<int,int>> seq;
  seq.push(std::make_pair(x,y));
  vis[y][x] = true;

  while(!seq.empty()){
    auto p = seq.front();
    seq.pop();
    x = p.first;
    y = p.second;
    for(const auto& of : offset){
      if(x - of[1] >= 0 && y - of[0] >= 0  // not out-of-index
        && !vis[y-of[0]][x - of[1]] // not vis
        && G[y-of[0]][x-of[1]] == '@'){ // have milk

        vis[y-of[0]][x - of[1]] = true;
        seq.push(std::make_pair(x-of[1],y-of[0]));
      }
    }
  }
}

int main(){
  while(true){
    std::cin >> m >> n;
    if(m == 0 && n == 0){
      break;
    }
    int ans = 0;
    std::memset(G, '\0', sizeof(G));
    std::memset(vis, false, sizeof(vis));

    for(int i = 0; i < m ;i++){
      scanf("%s", G[i]);
    }

    for(int y = 0; y < m; y++){
      for(int x = 0; x < n; x++){
        if(vis[y][x] || G[y][x] == '*')
          continue;
        bfs(x,y);
        ans++;
      }
    }
    std::cout << ans << std::endl;

  }
  return 0;
}
