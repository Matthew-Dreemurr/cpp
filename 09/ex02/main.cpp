#include "PmergeMe.hpp"
#include <iostream>

// #include <list>
#include <vector>

int main () {
    int a[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
    PmergeMe(a, 0, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << std::endl;
    }
    return 0;
}