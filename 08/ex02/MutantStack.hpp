#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iterator>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack() {}
		~MutantStack() {}
		MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
		MutantStack<T>& operator=(const MutantStack<T>& other) {std::stack<T>::operator=(other); return (*this); }

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {return this->c.begin(); }
		iterator end() {return this->c.end(); }
};

#endif /* MUTANTSTACK_H */
