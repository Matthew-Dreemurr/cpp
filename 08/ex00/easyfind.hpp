#ifndef EASYFIND_H
#define EASYFIND_H

template <typename T>
typename T::const_iterator easyfind(T & container, int tofind) {
	typename T::const_iterator	it;
	typename T::const_iterator	ite = container.cend();
	for (it = container.cbegin(); it != ite; it++)
	{	
		if (*it == tofind) {
			return it;
		}
	}
	return ite;
}

#endif /* EASYFIND_H */
