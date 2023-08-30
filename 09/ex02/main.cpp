#include "PmergeMe.hpp"
#include <iostream>

#include <list>
#include <vector>


template <typename T>
void test(T & container) {
    container.push_back(2);
    container.push_back(6);
    container.push_back(1);
    container.push_back(7);
    container.push_back(4);
    container.push_back(10);
    container.push_back(9);
    container.push_back(5);
    container.push_back(3);
    container.push_back(8);

    print_(container);
    PmergeMe(container);
    print_(container);

    std::cout << "===============" << std::endl;
}

int main () {
    std::vector<size_t> vec;
    test(vec);
    std::vector<size_t> list;
    test(list);
}