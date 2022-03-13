#include<cstdlib>
#include<iomanip>
#include<cassert>
#include<cstdio>
#include<string>
#include<iostream>
#include<queue>
#include<cstring>


#ifdef Local
#define test if(0)
#else
#define test if(0)
// poj's compiler does not support nullptr
#define nullptr NULL
#endif

typedef long long ll;

struct Node{
  ll weight;
  int ord;
  Node* left_node, *right_node;
  Node(ll weight, int ord, Node* left=nullptr, Node* right=nullptr): weight(weight), ord(ord), left_node(left), right_node(right){}
};

struct CompareFunctorImpl {
  bool operator ()(const Node* lhs, const Node* rhs) const {
    return lhs->weight > rhs->weight;
  }
};

int ord(const char &c){
  assert((c <= 'Z' && c >= 'A') || c == '_');
  if(c == '_') return 26;
  else return c - 'A';
}

void free_tree(Node * base){
  if(base->left_node != nullptr) free_tree(base->left_node);
  if(base->right_node != nullptr) free_tree(base->right_node);
  delete base;
}

Node* build_hofu_tree(const std::string& line){
  ll alphabet[27] = {0};
  for(int i = 0; i < line.size(); i++){
    const char& c = line[i];
    alphabet[ord(c)]++;
  }
  std::priority_queue<Node*, std::vector<Node*>, CompareFunctorImpl> seq;
  for(int i = 0; i < 27; i++){
    if(alphabet[i] > 0){
      seq.push(new Node(alphabet[i], i,  nullptr, nullptr));
    }
  }

  while(seq.size() > 1){
    Node* n1 = seq.top(); seq.pop();
    Node* n2 = seq.top(); seq.pop();
    test std::cout << n1->ord << " (" << n1->weight << ") merge with " << n2->ord << "(" << n2->weight << ")" << std::endl;
    Node* parent = new Node(n1->weight + n2->weight,-1,n1, n2);
    seq.push(parent);
  }
  return seq.top();
}

void dfs(const Node* n, ll (&result)[27], int depth){
  if(n->ord != -1){
    if(depth == 0){
      result[n->ord] = 1;
    }else{
      result[n->ord] = depth;
    }
    return;
  }
  if(n->right_node != nullptr){
    dfs(n->right_node, result, depth + 1);
  }
  if(n->left_node != nullptr){
    dfs(n->left_node, result, depth + 1);
  }
}

void solve(const std::string& line){
  ll alphabet_len[27] = {0};
  Node* tree = build_hofu_tree(line);
  dfs(tree, alphabet_len, 0);
  ll len = 0;
  for(int i = 0; i < line.size(); i++){
    const char&c = line[i];
    int idx = ord(c);
    test std::cout << c << " += " <<  alphabet_len[idx] << std::endl;
    len += alphabet_len[idx];
  }
  free_tree(tree);


  std::cout<<line.size() * 8<<" "<< len <<" "<<std::fixed<<std::setprecision(1)<<(double)(line.size() * 8)/len<<std::endl;
}

int main(){
  std::ios::sync_with_stdio(false);

  std::string line;

  while(std::getline(std::cin, line) && line != "END"){
    solve(line); 
    test std::cout << "-------------" << std::endl;
  }
  return 0;
}
