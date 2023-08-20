#include "iter.hpp"
#include <iostream>

void print_list_char (char * elem) {
	std::cout << "print_list_char " << elem << std::endl;
}

void print_list_const_int (const int elem) {
	std::cout << "print_list_char " << elem << std::endl;
}

void print_list_int (const int elem) {
	std::cout << "print_list_char " << elem << std::endl;
}

int main(int ac, char **av) {
	if (ac == 1) return 0;

	std::cout << "========== print_list_const_int ========== " << std::endl;

	iter(av, ac, print_list_char);

	std::cout << "========== print_list_const_int ========== " << std::endl;

	const int const_int_array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	iter(const_int_array, 10, print_list_const_int);

	std::cout << "========== print_list_int ========== " << std::endl;

	int int_array[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
	iter(int_array, 10, print_list_int);
}