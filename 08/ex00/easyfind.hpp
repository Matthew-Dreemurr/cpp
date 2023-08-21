#ifndef EASYFIND_H
#define EASYFIND_H

template <typename T>
int easyfind(T container, int tofind) {
	typename T::const_iterator	it;
	typename T::const_iterator	ite = container.end();
	// for (T::const_iterator it = container.begin(); it != container.end(); it++)
	for (it = container.begin(); it != ite; it++)
	{	
		if (*it == tofind) {
			return *it;
		}
	}
	return 0;
}

#endif /* EASYFIND_H */
