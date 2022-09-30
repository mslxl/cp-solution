void insert_index(int *va, int n,int index, int x){
	for(int i = n; i > index; i--){
		va[i] = va[i-1];
	}
	va[index + 1] = x;
}

// 插入适当位置并保持有序
void insert_element_order(int* va, int n, int x){
	for(int i = 0; i < n-1; i++){
		if(va[i] < x && va[i+1] >= x){
			insert_index(va, n, i, x);
			return;
		}
	}
	insert_index(va, n, n-1, x);
}
