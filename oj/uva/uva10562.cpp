#include <iostream>
#include <string>
#include <vector>
#include <cassert>

struct Node {
  char name;
  std::vector<Node*> children;
  Node(char name): name(name){}
};

std::vector<std::string> read_graph(){
  std::vector<std::string>> vector;
  std::string line;
  while(std::cin >> line && line != "#"){
    vector.push_back(line);
  }
  return vector;
}

Node* build_tree(const std::vector<std::string> &map, int x, int y, Node* parent){
  if(parent == nullptr){
    parent = new Node(map[y][x]);
  }
  if(map.size() - 1 < y) return nullptr;
  if(map[y+1] == '|'){
    int cursorX = x;
    while(map[y+2][cursorX] == '-'){
      cursorX--;
    }
    cursorX++;


  } else {
    return nullptr;
  }




}

void print_pre_order(const Node& node){

}

int main(){
  int T;
  std::cin >> T;
  while(T--){
    auto vector = read_graph();
    int x = 0;

    for(const auto& ch: vector[0]){
      x++;
      if(ch != ' '){
        break;
      }
    }
    Node* root = build_tree(vector, x, 0, nullptr);



  }

}
