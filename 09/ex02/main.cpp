#include "PmergeMe.hpp"
#include <iostream>

// #include <list>
#include <vector>

int main () {
    int a[] = { 1, 3, 10, 7, 9, 2, 4, 6, 8, 11, 5 };
    std::vector<size_t> vec;

    for (int i = 0; i < 11; i++) {
        vec.push_back(a[i]);
    }

    PmergeMe(vec);
    std::vector<size_t>::iterator it = vec.begin();
    std::vector<size_t>::iterator end = vec.end();
    for (int i = 0; it != end; it++, i++) {
        if ((i % K_DIV) == 0)
            std::cout << "---" << std::endl;
        std::cout << a[i] << " | " << *it << std::endl;
    }
    return 0;
}