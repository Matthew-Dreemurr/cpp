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
	std::list<int>::const_iterator it = easyfind<std::list<int> >(int_list, 3);
	if (it != int_list.end())
		std::cout << *it << std::endl;

	char c = 'a';

	std::vector<char>	char_vec;
	char_vec.push_back(c++);
	char_vec.push_back(c++);
	char_vec.push_back(c++);
	char_vec.push_back(c++);
	char_vec.push_back(c++);

	std::vector<char>::const_iterator it1 = easyfind<std::vector<char> >(char_vec, 'c');

	if (it1 != char_vec.cend())
		std::cout << *it1 << std::endl;

	it1 = easyfind<std::vector<char> >(char_vec, 'z');

	if (it1 != char_vec.cend()) {
		std::cout << *it1 << std::endl;
	} else {
		std::cout << "Not fount!" << std::endl;
	}

	return 0;
}