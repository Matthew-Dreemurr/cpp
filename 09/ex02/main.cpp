#include "PmergeMe.hpp"
#include <iostream>

#include <list>
#include <vector>
#include <typeinfo>

template <typename T>
void test(T &container, std::string type, char debug) {
    std::clock_t    start;

    if (debug == 'y') {
        std::cout << "Before: ";
        print_(container);
        std::cout << std::endl;
    }


    start = std::clock();

    PmergeMe(container);
    std::cout << "[" << type << "]" << " Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms for " << container.size() << " elements." << std::endl;

    if (debug == 'y') {
        std::cout << "After: " << std::endl;
        print_(container);
        std::cout << std::endl;
    }

}

int main (int ac, char **av) {
    if (ac < 3 || (av[1][0] != 'y' && av[1][0] != 'n')) {
        std::cout << "Usage: ./a.out debug: [n|y] int array: [int, ...]" << std::endl;
        return (1);
    }
    std::vector<size_t> vec;
    std::vector<size_t> list;
    // Convert and store all av in vec
    for (int i = 2; i < ac; i++) {
        // Check if av[i] is a number
        for (int j = 0; av[i][j]; j++) {
            if (av[i][j] < '0' || av[i][j] > '9') {
                std::cout << "Error: not valid number" << std::endl;
                return (1);
            }
        }
        vec.push_back(std::atoi(av[i]));
        list.push_back(std::atoi(av[i]));
    }
    test(vec, "Vector", av[1][0]);
    test(list, "List", av[1][0]);
}