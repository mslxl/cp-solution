
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// uva 101
using std::cin;
using std::cout;
using std::endl;
using std::vector;


int n;
vector<int> *piles;

void init_blocks() {
	piles = new vector<int>[n];
	for (int i = 0; i < n; i++)
		piles[i].push_back(i);
}
void print_piles() {
	for (int i = 0; i < n; i++)
	{
		cout << i << ": ";
		vector<int>& ref = piles[i];
		for (int j = 0; j < ref.size(); j++)
		{
			cout << ref[j];
			if (j != ref.size() - 1) {
				cout << " ";
			}
		}
		if (i != n - 1) {
			cout << endl;
		}
	}
}
// Search for the pile where the block in
vector<int>* find_block(int num) {
	for (int i = 0; i < n; i++)
	{
		vector<int>* ptr = &piles[i];
		for (auto start = ptr->begin(), last = ptr->end(); start != last; start++) {
			if (num == *start) {
				return &piles[i];
			}
		}
	}
	return nullptr; // Not found
}
void clear_above_blocks(int num) {
	vector<int>* ptr = find_block(num);
	for (int i = ptr->size() - 1; i >= 0; i--)
	{
		auto block = (*ptr) [i];
		if (block == num) {
			ptr->resize(i + 1);
			return;
		}
		else { 
			piles[block].push_back(block); 
		}
	}
}
void remove_above_blocks(int num) {
	vector<int>* ptr = find_block(num);
	for (int i = ptr->size() - 1; i >= 0; i--)
	{
		auto block = (*ptr) [i];
		if (block == num) {
			ptr->resize(i + 1);
			return;
		}
	}
}
void copy_block_above_to_pile(int srcNum, vector<int>* dst) {
	vector<int>* srcPtr = find_block(srcNum);
	int i = 0;
	bool startCopy = false;
	for (; i < srcPtr->size(); i++) {
		if ((*srcPtr)[i] == srcNum) {
			startCopy = true;
		}
		if (startCopy) {
			dst->push_back((*srcPtr)[i]);
		}
	}
}

int main(){
	int from, to;
	cin >> n;
	init_blocks();
	std::string cmd,task;
	while (cin >> cmd && cmd != "quit") {
		cin >> from >> task >> to;
		if (find_block(from) == find_block(to)) continue; // illeage cmd
		if (cmd == "move" && task == "onto") {
			clear_above_blocks(from);
			clear_above_blocks(to);
			auto from_pile = find_block(from);
			from_pile->resize(from_pile->size() - 1);
			auto to_pile = find_block(to);
			to_pile->push_back(from);
		}
		else if (cmd == "move" && task == "over") {
			clear_above_blocks(from);
			auto from_pile = find_block(from);
			from_pile->resize(from_pile->size() - 1);
			auto to_pile = find_block(to);
			to_pile->push_back(from);
		}
		else if (cmd == "pile" && task  == "onto") {
			clear_above_blocks(to);
			copy_block_above_to_pile(from, find_block(to));
			remove_above_blocks(from);
			auto from_pile = find_block(from);
			from_pile->resize(from_pile->size() - 1);
		}
		else if (cmd == "pile" && task == "over") {
			copy_block_above_to_pile(from, find_block(to));
			remove_above_blocks(from);
			auto from_pile = find_block(from);
			from_pile->resize(from_pile->size() - 1);
		}
	}
	print_piles();
	delete[] piles;
	return 0;
}