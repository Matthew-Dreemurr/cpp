#include <iostream>
#include "swap.hpp"
#include "min.hpp"

int main (void) {
	std::cout << "================================" << std::endl;
	int a = 2;
	int b = 3;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;

	std::cout << "================================" << std::endl;

	std::cout << "min(1, 2) = " << min(1, 2) << std::endl;
	std::cout << "min(2, 2) = " << min(2, 2) << std::endl;
	std::cout << "min(\"chaine1\", \"chaine2\") = " << min(c, d) << std::endl;
}