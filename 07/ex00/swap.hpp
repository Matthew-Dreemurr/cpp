#ifndef SWAP_H
#define SWAP_H

template <typename T>
void swap(T & a, T & b) {
	T tmp = a;
	a = b;
	b = tmp;
}

#endif /* SWAP_H */
