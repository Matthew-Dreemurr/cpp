#include "Array.hpp"
#include <iostream>

int main () {
	std::cout << "===== Test 1 =====" << std::endl;
    Array<int> intArray = Array<int>(5);

    std::cout << "intArray.size(): " << intArray.size() << std::endl;

    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i;
    }

	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << "intArray[" << i << "]: " << intArray[i] << std::endl;
	}

	std::cout << "===== Test 2 =====" << std::endl;

	Array<int> intArray2 = Array<int>(5);
	std::cout << "intArray2.size(): " << intArray2.size() << std::endl;
	intArray2 = intArray;

	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = i;
	}

	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << "intArray2[" << i << "]: " << intArray2[i] << std::endl;
	}

	std::cout << "===== Test 3 =====" << std::endl;

	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = 2;
	}

	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << "intArray[" << i << "]: " << intArray[i] << std::endl;
	}

	for (unsigned int i = 0; i < intArray2.size(); i++) {
		std::cout << "intArray2[" << i << "]: " << intArray2[i] << std::endl;
	}

	std::cout << "===== Test 4 =====" << std::endl;

	try {
		std::cout << "intArray[5]: " << intArray[5] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "===== Test 5 =====" << std::endl;

	try {
		std::cout << "intArray2[-1]: " << intArray2[-1] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}