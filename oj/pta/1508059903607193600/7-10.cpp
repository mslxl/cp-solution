#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
const int maxn = 30 + 17;
int N;
int in_order[maxn] = {0}, post_order[maxn] = {0};
struct Node{
	Node *left = nullptr, *right = nullptr;
	int value = -1;
} root;

void tree_build(Node* base,
	int* in_order_start, int* in_order_end,
	int* post_order_start, int* post_order_end){
		
	if(in_order_start >= in_order_end || post_order_start >= post_order_end) return;
	
	base->value = *(post_order_end - 1);
	test std::cout << "take base node " << (base->value) <<std::endl; 

	int* split = std::find(in_order_start, in_order_end, base->value);
	
	if(in_order_start < split){
		base->left = new Node();
		tree_build(base->left,
			in_order_start, split,
			post_order_start, post_order_start + (split - in_order_start));
	} 
	
	if(split+1 < in_order_end){
		base->right = new Node();
		tree_build(base->right,
			split+1,  in_order_end,
			post_order_start + (split - in_order_start), post_order_end - 1);  
	}
}
void floor_each(Node* node){
	std::queue<Node*> seq;
	std::queue<Node*> ret;
	seq.push(node);
	ret.push(node);
	while(!seq.empty()){
		const auto p = *seq.front();
		seq.pop();
		if(p.left != nullptr && p.left->value != -1){
			seq.push(p.left);
			ret.push(p.left);
		}
		if(p.right != nullptr && p.right->value != -1){
			seq.push(p.right);
			ret.push(p.right);
		}
	}
	std::cout << ret.front()->value;
	ret.pop();
	while(!ret.empty()){
		const auto item = *ret.front();
		ret.pop();
		std::cout << ' '<< item.value;
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> N;
	rep(i, 0, N) std::cin >> post_order[i];
	rep(i, 0, N) std::cin >> in_order[i];
	tree_build(&root,in_order,in_order + N, post_order, post_order + N);
	floor_each(&root);
	return 0;
}

