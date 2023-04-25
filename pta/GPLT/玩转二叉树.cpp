#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
int N;
int *in_order, *pre_order; 

struct Node{
	int value;
	Node* left = nullptr;
	Node* right = nullptr;
};

Node* build_tree(int *pre_order_begin, int *pre_order_end,
				int *in_order_begin, int* in_order_end){
					
	if(pre_order_begin >= pre_order_end || in_order_begin >= in_order_end) return nullptr;
	
	Node* base = new Node();
	base->value = *pre_order_begin;
	
	int* split = std::find(in_order_begin, in_order_end, base->value);
	
	if(in_order_begin < split){
		base->left = 
			build_tree(pre_order_begin + 1, pre_order_begin + 1 + (split - in_order_begin),
				in_order_begin, split);
	}
	if(split + 1 < in_order_end){
		base->right = 
			build_tree(pre_order_begin + 1 + (split - in_order_begin), pre_order_end,
				split + 1, in_order_end);
	}
	return base;
}

void flip_tree(Node* node){
	if(node != nullptr){
		flip_tree(node->left);
		flip_tree(node->right);
		std::swap(node->left, node->right);
	}
}

void floor_print(Node* node){
	std::queue<Node*> seq;
	seq.push(node);
	bool fst = true;
	while(!seq.empty()){
		Node* elem = seq.front();
		seq.pop();
		if(!fst){
			std::cout << ' ';
		}
		std::cout << elem->value;
		fst = false;
		if(elem->left != nullptr) seq.push(elem->left);
		if(elem->right != nullptr) seq.push(elem->right);
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> N;
	in_order = new int[N];
	pre_order = new int[N];
	rep(i,0,N) std::cin >> in_order[i];
	rep(i,0,N) std::cin >> pre_order[i];
	
	Node* root = build_tree(pre_order, pre_order + N, in_order, in_order+N);
	flip_tree(root);
	floor_print(root);
	return 0;
}

