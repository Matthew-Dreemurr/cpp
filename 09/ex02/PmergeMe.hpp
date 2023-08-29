#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <iostream>

#define K_DIV 3

template <typename T>
void    insert(T & container, const typename T::iterator & begin, const size_t len_div) {
    typename T::iterator ptr = begin;

    for (size_t i = 0; i < len_div - 1; i++, ptr++) {

        if (*(ptr + 1) < *ptr) {
            
            for (typename T::iterator iptr = begin; iptr != (ptr + 1); iptr++) {

                if (*(ptr + 1) < *iptr) {
                    size_t tmp = *(ptr+1);
                    container.erase(ptr + 1);
                    container.insert(iptr, tmp);
                }
            }
        }
    }
}

template <typename T>
void    PmergeMe(T & container) {
    for (size_t i = 0; i < container.size(); i += K_DIV) {
        typename T::iterator a = container.begin() + i;
        if (container.size() - i >= K_DIV) {
            insert(container, a, K_DIV);
        } else {
            insert(container, a, container.size() - i);
        }
    }
}


#endif /* PMERGEME_HPP */
