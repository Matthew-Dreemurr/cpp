#ifndef SPAN_H
#define SPAN_H

#include <vector>

class Span
{
private:
	std::vector<int> store;
public:
	Span();
	Span(unsigned int n);
	Span(const Span & newSpan);
	Span & operator=(const Span & newSpan);
	~Span();

	void addNumber(int n);
	void autoAddNumbers();

	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif /* SPAN_H */
