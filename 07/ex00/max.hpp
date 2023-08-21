#ifndef MAX_H
#define MAX_H

template <typename T>
T & max(T & a, T & b) {
	return (a > b ? a : b);
}

template <typename T>
const T & max(const T & a, const T & b) {
	return (a > b ? a : b);
}

#endif /* MAX_H */
