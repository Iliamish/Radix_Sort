#include <iostream>
#include <conio.h>
#include "sort.h"

int main() {
	std::vector<int> vec{0, 100, 101, 55, 1, 2, 6, 7, 14, 63, 11, 24, 9, 59, 21, 22, 44, 78, 34, 98, 76, 8, 101, 231, 21, 314, 600, 201 };
	for (auto& item : sort::radix_sort(vec, 3, 10)) {
		std::cout << item << std::endl;
	}
	_getch();
	return 0;
}