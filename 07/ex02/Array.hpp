#ifndef ARRAY_H
#define ARRAY_H

#include <exception>
#include <iostream>

template <typename T>
class Array
{
	class IndexOutOfRangeException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Index out of range";
		}
	};

private:
	T *				_array;
	unsigned int	_size;
public:
	Array();
	Array(unsigned int n);
	Array(Array const &other);
	Array &operator=(Array const &other);

	T &operator[](unsigned int i);
	unsigned int size() const;

	~Array();
};

#include "Array.tpp"

#endif /* ARRAY_H */
