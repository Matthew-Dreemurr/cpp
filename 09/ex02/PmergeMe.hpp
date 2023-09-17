#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <iostream>
#include <algorithm>



#define K_DIV 7

template <typename T>
void print_(T & container) {
    for (typename T::iterator it = container.begin(); it != container.end(); it++) {
        std::cout << *it << " " ;
    }
    std::cout << std::endl;
}

template<typename T>
void insertionSort(T& container)
{
	size_t temp;
	typename T::iterator it;
	typename T::iterator prev;
	typename T::iterator index;
    for (it = container.begin(); it != container.end(); ++it)
	{
		temp = *it;
		index = it;
		while (index != container.begin()) {
			prev = index;
			--prev;
			if (*prev > temp) {
				*index = *prev;
				--index;
			}
			else
				break;
		}
		*index = temp;
	}
}

template <typename T>
void mergeInsertsort(T& container)
{
	size_t	len = container.size();

	if (len > K_DIV)
	{
		typename T::iterator begin = container.begin();
		typename T::iterator mid = container.begin();
		std::advance(mid, container.size() / 2);
		typename T::iterator end = container.end();
		T left(begin, mid);
		T right(mid, end);
		if (left.size() > 1)
			mergeInsertsort(left);
		if (right.size() > 1)
			mergeInsertsort(right);
		std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
	}
	else
		insertionSort(container);
}

template <typename T>
void    PmergeMe(T & container) {
    
    // Remove duplicate values
    for (typename T::iterator it = container.begin(); it != container.end(); it++) {
        for (typename T::iterator it2 = it + 1; it2 != container.end(); it2++) {
            if (*it == *it2) {
                container.erase(it2);
                it2--;
            }
        }
    }
    mergeInsertsort(container);
}

#endif /* PMERGEME_HPP */
