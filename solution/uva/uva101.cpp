#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int n;
vector<int> *piles;
void prt_piles()
{
	for (int i = 0; i < n; i++)
	{
		auto &elem = piles[i];
		cout << i << ":";
		for (int j = 0; j < elem.size(); j++)
		{
			cout << " " << elem[j];
		}
		cout << endl;
	}
}

void remove_block(int block, vector<int> &ptr)
{
	auto start = ptr.begin(), last = ptr.end();
	while (start != last)
	{
		if (*start == block)
		{
			ptr.erase(start, start + 1);
			return;
		}
		start++;
	}
}
void remove_above(int block, vector<int> &ptr)
{
	auto start = ptr.begin(), last = ptr.end();
	while (start != last)
	{
		if (*start == block)
		{
			ptr.erase(start, last);
			return;
		}
		start++;
	}
}
void recover_block(int block)
{
	piles[block].push_back(block);
}
void recover_above(int block, vector<int> &ptr)
{
	vector<int> to_recover;
	auto start = ptr.end() - 1, last = ptr.end();
	while (start != ptr.begin() - 1)
	{
		if (*start == block)
		{
			ptr.erase(start + 1, last);
			break;
		}
		to_recover.push_back(*start);
		start--;
	}
	for (auto start = to_recover.begin(), last = to_recover.end(); start != last; start++)
	{
		recover_block(*start);
	}
}

vector<int> *find_pile(int block)
{
	for (int i = 0; i < n; i++)
	{
		vector<int> &ref = piles[i];
		for (auto item : ref)
		{
			if (item == block)
			{
				return &ref;
			}
		}
	}
	return nullptr;
}

void move_above(int block, vector<int> &src, vector<int> &dst)
{
	if (src == dst)
		return;
	bool cpy = false;
	for (auto start = src.begin(), last = src.end(); start != last; start++)
	{
		if (*start == block)
		{
			cpy = true;
		}
		if (cpy)
		{
			dst.push_back(*start);
		}
	}

	for (auto start = src.begin(), last = src.end(); start != last; start++)
	{
		if (*start == block)
		{
			src.erase(start, last);
			return;
		}
	}
}

int main()
{
	cin >> n;
	piles = new vector<int>[n];
	for (int i = 0; i < n; i++)
		piles[i].push_back(i);
	std::string cmd, task;
	int a, b;
	while (cin >> cmd && cmd != "quit")
	{
		cin >> a >> task >> b;
		auto aPile = find_pile(a);
		auto bPile = find_pile(b);
		if (aPile == bPile)
			continue;
		if (cmd == "move" && task == "onto")
		{
			recover_above(a, *aPile);
			recover_above(b, *bPile);
			remove_block(a, *aPile);
			bPile->push_back(a);
		}
		else if (cmd == "move" && task == "over")
		{
			recover_above(a, *aPile);
			remove_block(a, *aPile);
			find_pile(b)->push_back(a);
		}
		else if (cmd == "pile" && task == "onto")
		{
			recover_above(b, *bPile);
			move_above(a, *find_pile(a), *bPile);
		}
		else if (cmd == "pile" && task == "over")
		{
			move_above(a, *find_pile(a), *find_pile(b));
		}
	}
	prt_piles();
	return 0;
}