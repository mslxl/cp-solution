#include<iostream>

struct LinkedNode{
	int value;
	LinkedNode* next;
};

struct LinkedNodeHead { //首元节点
	LinkedNode* first;
	int len;
};

void insert_head(LinkedNodeHead* head, LinkedNode* node){
	node->next = head->first;
	head->first = node;
}

void reverse_linkedlist(LinkedNodeHead* head){
	if(head->len < 2) return; //只有一个节点没有 reverse 的必要
	
	LinkedNode* origin_first = head->first; // 原来的第一个会变成最后一个，所以要先保存起来，最后将 next 设为 null
	LinkedNode* origin_next = head->first->next;

	LinkedNode* node = nullptr;
	while(origin_next != nullptr){
		node = origin_next;
		origin_next = node->next;
		insert_head(head, node);
	}
	origin_first->next = nullptr;
}

// 下为测试代码，作业不需要，仅供测试理解


// 按顺序输出链表
void print_linkedlist(LinkedNodeHead * head){
	for(LinkedNode* node = head->first; node != nullptr; node = node->next){
		std::cout << node->value << " ";
	}
	std::cout << std::endl;
}

// 便于创建链表的辅助函数
LinkedNode* create_node(int value, LinkedNode* next){
	return new LinkedNode{
		value,
		next
	};
}

LinkedNodeHead* create_node_head_of(LinkedNode* n){
	int len = 0;
	for(LinkedNode* node = n; node != nullptr; node = node->next){
		len++;
	}
	
	return new LinkedNodeHead{
		n,
		len
	};
}

int main(){
	LinkedNodeHead* linkedlist = create_node_head_of(create_node(1, create_node(2, create_node(3, create_node(4, create_node(5, nullptr))))));
	std::cout << "before: ";
	print_linkedlist(linkedlist);
	
	std::cout << "after: ";
	reverse_linkedlist(linkedlist);
	print_linkedlist(linkedlist);
	
	return 0;
}
