#include "easyfind.hpp"
#include <list>
#include <vector>
#include <iostream>

int main () {
	std::list<int>		int_list;
	int i = 0;
	int_list.push_back(i++);
	int_list.push_back(i++);
	int_list.push_back(i++);
	int_list.push_back(i++);
	int_list.push_back(i++);

	std::cout << easyfind<std::list<int> >(int_list, 3) << std::endl;

	char c = 'a';

	std::vector<char>	char_vec;
	char_vec.push_back(c++);
	char_vec.push_back(c++);
	char_vec.push_back(c++);
	char_vec.push_back(c++);
	char_vec.push_back(c++);

	std::cout << easyfind<std::vector<char> >(int_list, 99) << std::endl;//TODO FIX
}