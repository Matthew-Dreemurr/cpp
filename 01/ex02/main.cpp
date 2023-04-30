#include "iostream"

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	// print the address of the string
	std::cout << "address of str       : " << &str << std::endl;
	std::cout << "address of stringPTR : " << stringPTR << std::endl;
	std::cout << "address of stringREF : " << &stringREF << std::endl;

	std::cout << "str                  : " << str << std::endl;
	std::cout << "stringPTR            : " << *stringPTR << std::endl;
	std::cout << "stringREF            : " << stringREF << std::endl;
	return 0;
}
