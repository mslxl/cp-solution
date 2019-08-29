#include<iostream>
#include<cstring>


void print_array(int* begin, int* end) {
	std::cout << '{';
	for (auto i = begin; i != end; i++) {
		std::cout << *i;
		if (i + 1 != end) {
			std::cout << ',';
		}
	}
	std::cout << '}' << std::endl;
}

struct S {
	int compare = 0, swap = 0;
};

S* quick_sort(int* begin, int* end) {
	auto s = new S;
	auto left = begin, right = end - 1;

	if (left >= right) {
		return s;
	}
	int tmp = *left; // 基准数
	while (left != right) {
		while (*(right) >= tmp && left < right) {
			s->compare++;
			right--;
		}
		while (*(left) <= tmp && left < right) {
			s->compare++;
			left++;
		}
		if (left < right) {
			s->swap++;
			auto t = *left;
			*left = *right;
			*right = t;
		}
	}
	*begin = *left;
	*left = tmp;
	s->compare++;
	auto t = quick_sort(begin, left + 1);
	s->compare += t->compare;
	s->swap += t->swap;
	delete t;
	t = quick_sort(left + 1, end);
	s->compare += t->compare;
	s->swap += t->swap;
	delete t;
	return s;
}

S* bucket_sort(int* begin, int* end){
	auto s = new S;
	auto i = begin;

	int n[1024];
	std::memset(n,0,sizeof(n));

	do {
		n[*i]++;
		s->compare++;
	} while ((++i) != end);

	
	for (auto j = 0; j < 1024; j++)
	{
		while(n[j]-- > 0){
			s->swap++;
			*(begin++) = j;
		}
	}

	return s;
}

S* bubble_sort(int* begin, int* end) {
	S* s = new S;
	int compare = 0, swap = 0;
	for (auto i = begin; i != end; ++i) {
		for (auto j = begin; j != end - (i - begin + 1); ++j) {
			s->compare++;
			if (*j > *(j+1)) {
				s->swap++;
				auto k = j + 1;
				std::swap(*j,*k);
			}
		}
	}
	return s;
}

int main() {
	int arr[] = { 4,3,5,6,7,8,9,1,2,3,12,8,23,56,56,98,45,3,56,78,59,26,45,26,84,312,465,478,78,465 };
	auto offset = sizeof(arr) / sizeof(int);

	std::cout << "Before sort:";
	print_array(arr, arr + offset);
	std::cout << "Length: " << offset << std::endl << std::endl;

	//Bubble Sort
	int* tmp = new int[sizeof(arr) / sizeof(int)];
	std::memcpy(tmp, arr, sizeof(arr));
	auto begin = tmp;
	auto end = begin + offset;
	auto s = bubble_sort(begin, end);
	std::cout <<"After bubble sort :";
	print_array(begin, end);
	std::cout << "Compare: " << s->compare << std::endl
		<< "Swap: " << s->swap << std::endl << std::endl;
	delete s;

	//Bucket Sort
	std::memcpy(tmp, arr, sizeof(arr));
	s = bucket_sort(begin, end);
	std::cout << "After bucket sort :";
	print_array(begin, end);
	std::cout << "Compare: " << s->compare << std::endl
		<< "Swap: " << s->swap << std::endl << std::endl;
	delete s;

	//Quick Sort
	std::memcpy(tmp, arr, sizeof(arr));
	s = quick_sort(begin, end);
	std::cout << "After quick sort :";
	print_array(begin, end);
	std::cout << "Compare: " << s->compare << std::endl
		<< "Swap: " << s->swap << std::endl << std::endl;
	delete s;
	
	
	
	
	

}