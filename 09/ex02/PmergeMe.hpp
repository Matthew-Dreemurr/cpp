#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>

template <typename T>
void    merge(T* array, size_t start, size_t mid, size_t end) {
    T* tmp = new T[end - start];
    size_t start_ = start;
    size_t mid_ = mid;
    size_t index = 0;

    while (start_ < mid && mid_ < end) {
        if (array[start_] < array[mid_]) {
            tmp[index] = array[start_];
            start_++;
        } else {
            tmp[index] = array[mid_];
            mid_++;
        }
        index++;
    }
    while (start_ < mid) {
        tmp[index] = array[start_];
        start_++;
        index++;
    }
    while (mid_ < end) {
        tmp[index] = array[mid_];
        mid_++;
        index++;
    }
    for (size_t i = start; i < end; i++) {
        array[i] = tmp[i - start];
    }
    delete[] tmp;
}

template <typename T>
void    insertionSort(T* array, size_t start, size_t end) {
    for (size_t i = start + 1; i < end; i++) {
        T tmp = array[i];
        size_t j = i;
        while (j > start && array[j - 1] > tmp) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = tmp;
    }
}

template <typename T>
void    PmergeMe(T* array, size_t start, size_t end) {
    if (end - start > 11) {
        int mid = (start + end) / 2;
        PmergeMe(array, start, mid);
        PmergeMe(array, mid, end);
        merge(array, start, mid, end);
    } else {
        insertionSort(array, start, end);
    }
}


#endif /* PMERGEME_HPP */
