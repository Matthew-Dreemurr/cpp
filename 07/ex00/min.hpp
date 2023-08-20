#ifndef MIN_H
#define MIN_H

template <typename T>
const T & min(T & a, T & b) {
	return (a < b ? a : b);
}

template <typename T>
const T & min(const T & a, const T & b) {
	return (a < b ? a : b);
}

#endif /* MIN_H */
