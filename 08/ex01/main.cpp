#include "Span.hpp"
#include <iostream>

#include <thread>
#include <atomic>
#include <chrono>
#include <exception>

int main()
{

	std::cout << "==========" << std::endl;

	try
	{
		Span sp = Span();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}

	std::cout << "==========" << std::endl;

	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}

	std::cout << "==========" << std::endl;

	try
	{
		Span sp = Span();
		sp.addNumber(12);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}

	std::cout << "==========" << std::endl;

try
	{
		Span sp = Span(2);
		sp.addNumber(1);
		std::cout << "V"<< std::endl;
		sp.addNumber(2);
		std::cout << "V"<< std::endl;
		sp.addNumber(3);
		std::cout << "X"<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}

	std::cout << "==========" << std::endl;

	try {
		std::vector<int>	l(10000);
		std::srand(time(NULL));
		std::generate(l.begin(), l.end(), std::rand);

		Span sp (l.size());

		sp.addNumber(l);

		std::cout << sp.longestSpan() << std::endl;

		std::cout << sp.shortestSpan() << std::endl;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl; 
	}

	return 0;
}