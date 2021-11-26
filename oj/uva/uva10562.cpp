#include <iostream>
#include <string>
#include <vector>

void read_str(std::vector<std::string>& vec) {
    std::string ln;
    vec.clear();
    while (getline(std::cin, ln), ln != "#") {
        vec.push_back(ln);
    }
}

void print_answer(int x, int y, const std::vector<std::string>& G) {
    if(G.size()==0) return;
    if(G[y][x] == '#') return;
    std::cout << G[y][x];
    std::cout << '(';
    y++;
    if(y < G.size() && G[y][x] == '|'){
      y++;
      for (; x > 0 && G[y][x - 1] == '-'; x--);
      for (; G[y][x] == '-'; x++) {
          if (G[y].size() > x && G[y + 1][x] != ' ' && G[y + 1][x] != '\n' && G[y + 1][x] != '\0') {
              print_answer(x, y + 1, G);
          }
      }
    }
    std::cout << ')';
}

int main() {
    int T;
    std::cin >> T;
    getchar();
    std::vector<std::string> G;
    while (T--) {
        read_str(G);
        if(G.size() == 0){
          std::cout << "()" << std::endl;
        } else {
          int x = 0;
          for(; G[0][x] == ' '; x++);
          std::cout << '(';
          print_answer(x,0,G);
          std::cout << ')';
          std::cout << std::endl;
        }
    }
}
