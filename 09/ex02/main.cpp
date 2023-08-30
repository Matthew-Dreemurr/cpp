#include "PmergeMe.hpp"
#include <iostream>

#include <vector>
#include <deque>

void test(std::vector<size_t> &vec, std::deque<size_t> &deque) {
    std::clock_t    start_vec, start_deque, end_vec, end_deque;

    std::cout << "Before: "; print_(vec);

    start_vec = std::clock();
    PmergeMe(vec);
    end_vec = std::clock();

    start_deque = std::clock();
    PmergeMe(deque);
    end_deque = std::clock();

    std::cout << "After: "; print_(vec);

    std::cout << "[std::vector<int>]" << " Time: " << (end_vec - start_vec) / (double)(CLOCKS_PER_SEC / 1000) << " ms for " << vec.size() << " elements." << std::endl;
    std::cout << "[std::deque<int>]" << " Time: " << (end_deque - start_deque) / (double)(CLOCKS_PER_SEC / 1000) << " ms for " << deque.size() << " elements." << std::endl;
}

int main (int ac, char **av) {
    if (ac < 2) {
        std::cout << "Error" << std::endl;
        return (1);
    }
    std::vector<size_t> vec;
    std::deque<size_t> deque;
    // Convert and store all av in vec
    for (int i = 1; i < ac; i++) {
        // Check if av[i] is a number
        if (!av[i][0]) {
            std::cout << "Error" << std::endl;
            return (1);
        }
        for (int j = 0; av[i][j]; j++) {
            if (av[i][j] < '0' || av[i][j] > '9') {
                std::cout << "Error" << std::endl;
                return (1);
            }
        }
        vec.push_back(std::atoi(av[i]));
        deque.push_back(std::atoi(av[i]));
    }
    test(vec, deque);
}