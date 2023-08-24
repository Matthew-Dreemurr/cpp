#include "Span.hpp"

Span::Span()
: _store(0), _max(0), _current(0)
{}

Span::Span(unsigned int n) 
: _store(0), _max(n), _current(0)
{}

Span::Span(const Span & newSpan) 
: _store(newSpan._store), _max(newSpan._max), _current(newSpan._current)
{}

Span & Span::operator=(const Span & newSpan) {
	_store = newSpan._store;
	_max = newSpan._max;
	_current = newSpan._current;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
	const unsigned int tmp = _current + 1;

	if (tmp > _max) {
		throw Span::IsFull();
	}

	_store.push_back(n);
	_current = tmp;
}

void Span::addNumber(std::vector<int> v) {
	const unsigned int tmp = _current + v.size();

	if (tmp > _max) {
		throw Span::IsFull();
	}

	std::vector<int>::const_iterator end = _store.cend();
	_store.insert(end, v.cbegin(), v.cend());
	_current = tmp;
}

unsigned int Span::shortestSpan() {
	if (_current < 2) {
		throw Span::NotEnoughData();
	}

	unsigned int min = Span::longestSpan();

	for (std::vector<int>::const_iterator it = _store.cbegin(); it != _store.cend(); it++) {
		for (std::vector<int>::const_iterator nit = _store.cbegin(); nit != _store.cend(); nit++) {
			if (*it == *nit) {
				continue;
			}
			const unsigned int tmp = std::abs(*nit - *it);
			if (tmp < min) {
				min = tmp;
			}
		}
	}
	return min;
}

unsigned int Span::longestSpan() {

	if (_current < 2) {
		throw Span::NotEnoughData();
	}

	std::vector<int>::const_iterator it = _store.cbegin();
	std::vector<int>::const_iterator ite = _store.cend();

	int max = std::numeric_limits<int>::min();
	int min = std::numeric_limits<int>::max();

	while (it != ite) {
		(*it > max) ? max = *it : 0;
		(*it < min) ? min = *it : 0;
		it++;
	}
	return (max - min);
}

Span::IsFull::IsFull()
: std::runtime_error("Span is full!")
{}

Span::NotEnoughData::NotEnoughData()
: std::runtime_error("Not enough dataset!")
{}