//
// Created by fluffy on 1/3/23.
//

#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < argc; ++i) {
		for (int x = 0; argv[i][x]; ++x) {
			std::cout << (char)std::toupper(argv[i][x]);
		}
	}
	std::cout << std::endl;

	return (0);
}