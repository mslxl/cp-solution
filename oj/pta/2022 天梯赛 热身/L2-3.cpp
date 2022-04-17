#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

struct Node{
	int value;
	int depth;
	Node* left =nullptr, *right = nullptr;
};

const int maxn = 20 + 17;
int inorder[maxn], postorder[maxn];
int N;
Node* build_tree(int inleft, int inright, int postleft, int postright, int depth){
	if(inright < inleft || postright < postleft) return nullptr;
	
	Node *base = new Node();
	base->value = postorder[postright];
	base->depth = depth;
	int split = 0;
	for(int i = inleft; i <= inright;i++){
		if(inorder[i] == base->value){
			split = i;
			break;
		}
	}
	
	base->left = build_tree(inleft, split - 1, postleft, postleft + (split - 1 - inleft), depth + 1);
	base->right = build_tree(split + 1, inright, postleft + (split  - inleft), postright - 1, depth + 1);
	return base;
}


std::vector<std::vector<int>> mirror(20);

void bfs(Node* base){
	std::queue<Node*> seq;
	std::vector<Node*> nodes;
	seq.push(base);
	while(!seq.empty()){
		Node* node = seq.front();
		seq.pop();
		mirror[node->depth].push_back(node->value);
		tout << "process " << node -> value << std::endl; 
		if(node->left != nullptr) seq.push(node->left);
		if(node->right != nullptr) seq.push(node->right);
	}
}

int main(){
	std::cin >> N;
	rep(i, 0, N) std::cin >> inorder[i];
	rep(i, 0, N) std::cin >> postorder[i];
	Node* tree = build_tree(0, N-1, 0, N-1, 0);
	bfs(tree);
	std::cout << "R:";
	for(const auto& item: mirror){
		if(item.empty()){
			break;
		}
		std::cout << ' ' << item[item.size() - 1];
	}
	std::cout << std::endl << "L:";
	for(const auto& item: mirror){
		if(item.empty()){
			break;
		}
		std::cout << ' ' << item[0];
	}
}
