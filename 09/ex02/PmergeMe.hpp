#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <iostream>

#define K_DIV 7

template <typename T>
void print_(T & container) {
    for (typename T::iterator it = container.begin(); it != container.end(); it++) {
        std::cout << *it << " " ;
    }
    std::cout << std::endl;
}

template <typename T>
std::pair<typename T::iterator, typename T::iterator> do_insert (
    T & container,
    typename T::iterator begin,
    typename T::iterator end,
    typename T::iterator self
) {
    typename T::iterator it;
    for(it = begin; it != end; it++) {
        if (*self < *it) {
            const size_t tmp = *self;
            self = container.erase(self);
            it = container.insert(it, tmp);
            self = container.begin() + std::distance(container.begin(), it);
            it = container.begin() + std::distance(container.begin(), it);
            break;
        }
    }
    return std::make_pair(self, it);
}

template <typename T>
typename T::iterator insert(T & container, const typename T::iterator & begin, const size_t len_div) {
    if (len_div < 2)
        return container.begin();

    typename T::iterator ptr = begin + 1;

    for (size_t i = 1; i < len_div; ++i, ++ptr)
    {
        if (*ptr < *(ptr - 1))
        {
            size_t tmp = *ptr;
            ptr = container.erase(ptr);
            typename T::iterator pos = std::upper_bound(begin, ptr, tmp);
            ptr = container.insert(pos, tmp);
        }
    }
    return ptr;
}

template <typename T>
typename T::iterator getEnd(T & container, typename T::iterator list2, size_t len) {
    for (size_t i = 0; i < len && list2 != container.end(); i++, list2++);
    return list2;
}

template <typename T>
void merge(T & container, typename T::iterator list1, typename T::iterator list2, size_t len) {
    const typename T::iterator begin = list1;
    const typename T::iterator end = getEnd(container, list2, len);

    while (list1 != list2 && list2 != end) {
        if (*list1 < *list2) {
            std::pair<typename T::iterator, typename T::iterator> new_iters = do_insert(container, begin, list1 + 1, list1);
            list1 = new_iters.first;
            list1++;
        } else {
            std::pair<typename T::iterator, typename T::iterator> new_iters = do_insert(container, begin, list1 + 1, list2);
            list2 = new_iters.first;
            list2++;
        }
    }
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

     // Insertion sort
    for (size_t i = 0; i < container.size(); i += K_DIV) {
        typename T::iterator a = container.begin() + i;
        if (container.size() - i >= K_DIV) {
            a = insert(container, a, K_DIV);
        } else {
            a = insert(container, a, container.size() - i);
        }
    }

    // Merge
    for (size_t len = K_DIV; len <= container.size(); len *= 2) {
        size_t  nb_arr = container.size() / len + !!(container.size() % len);
        for (size_t i = 0; i < nb_arr; i += 2) {
            if (nb_arr == 1 || !(i == nb_arr - 1 && nb_arr % 2)){
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
