#include<iostream>



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
	S* s = new S;

	auto pivot = begin;
	auto i = begin - 1;

	while (++i != end) {// Put less num to left
		s->compare++;
		if (*i < *pivot && i > pivot) {
			s->swap++;
			std::swap(*i, *pivot);
			pivot = i;
		}
	}

	i = end;

	while (--i != begin - 1) {
		s->compare++;
		if (*i > * pivot && i < pivot) {
			s->swap++;
			std::swap(*i, *pivot);
			pivot = i;
		}
	}
	if (pivot - begin > 1) {
		auto subS = quick_sort(begin, pivot);
		s->compare += subS->compare;
		s->swap += subS->compare;
		delete subS;

	}
	
	if (end - pivot > 0) {
		auto subS = quick_sort(pivot + 1, end);
		s->compare += subS->compare;
		s->swap += subS->compare;
		delete subS;
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
	int arr[] = { 4,3,5,6,7,8,9,1,2,3,12,8,23,56,56,98,45,3,56,78,59,26,45,26,84,312,465,978,78,465 };
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

	std::memcpy(tmp, arr, sizeof(arr));
	s = quick_sort(begin, end);
	std::cout << "After quick sort :";
	print_array(begin, end);
	std::cout << "Compare: " << s->compare << std::endl
		<< "Swap: " << s->swap << std::endl << std::endl;
	delete s;
	
	
	
	
	

}