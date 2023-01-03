struct LinkedNode {
	int value;
	LinkedNode* next;
};


LinkedNode head_node;

// 回溯时插入至少常数小点?
LinkedNode* reverse_dfs(LinkedNode* head_node, LinkedNode* cur_node) {
	if (cur_node->next != nullptr) {
		LinkedNode* prior_node = reverse_dfs(head_node, cur_node);
		prior_node->next = cur_node;
	} else {
		head_node->next = cur_node;
	}
	return cur_node;
}

void reverse(LinkedNode* head_node) {
	if (head_node->next == nullptr) return;
	LinkedNode* last_node_after = head_node->next;
	reverse_dfs(head_node, head_node->next);
	last_node_after->next = nullptr;
}


