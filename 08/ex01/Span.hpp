#ifndef SPAN_H
#define SPAN_H

#include <vector>
#include <stdexcept>
#include <limits>
#include <cstdlib> 

class Span
{
private:
	std::vector<int>	_store;
	unsigned int		_max;
	unsigned int		_current;
public:
	Span();
	Span(unsigned int n);
	Span(const Span & newSpan);
	Span & operator=(const Span & newSpan);
	~Span();

	void addNumber(int n);
	void addNumber(std::vector<int> v);

	unsigned int shortestSpan();
	unsigned int longestSpan();

	class IsFull: public std::runtime_error{
		public:
			IsFull();
	};

	class NotEnoughData: public std::runtime_error{
		public:
			NotEnoughData();
	};
};

#endif /* SPAN_H */
