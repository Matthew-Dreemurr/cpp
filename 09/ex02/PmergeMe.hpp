#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <iostream>

#define K_DIV 3

template <typename T>
void do_insert (
    T & container,
    typename T::iterator begin,
    typename T::iterator end,
    typename T::iterator self
) {
    for(typename T::iterator it = begin; it != end; it++) {
        if (*self < *it) {
            const size_t tmp = *self;
            container.erase(self);
            container.insert(it, tmp);
        }
    }
}

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
typename T::iterator getEnd(T & container, typename T::iterator list2, size_t len) {
    for (size_t i = 0; i < len && list2 != container.end(); i++, list2++);
    return list2;
}

template <typename T>
void    merge(T & container, typename T::iterator list1, typename T::iterator list2, size_t len) {
    const typename T::iterator begin = list1;
    const typename T::iterator end = getEnd(container, list2, len);

    while (list1 != list2 && list2 != end) {
        if (*list1 > *list2) {//TODO FIX SEGFAULT
            do_insert(container, begin, list1, list1);
            list1++;
        } else {
            do_insert(container, begin, list1, list2);
            list2++;
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
    for (size_t len = K_DIV; len <= container.size() * 2; len *= 2) {
        size_t  nb_arr = container.size() / len + !!(container.size() % len);
        for (size_t i = 0; i < nb_arr; i += 2) {
            if (nb_arr == 1 || !(i == nb_arr - 1 && nb_arr % 2)){
                std::cout << len << ": " << nb_arr << std::endl;
                merge(
                    container,
                    container.begin() + i * len,
                    container.begin() + (i + 1) * len,
                    len
                );
            }
        }
    }


}


#endif /* PMERGEME_HPP */
