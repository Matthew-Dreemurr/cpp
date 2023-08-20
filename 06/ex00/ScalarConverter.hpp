#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter & other);
		ScalarConverter & operator=(const ScalarConverter & other);
		~ScalarConverter();


		static std::string toChar(const double & val);
		static std::string toInt(const double & val);
		static std::string toFloat(const double & val);
		static std::string toDouble(const double & val);


	public:
		static void convert(const std::string & str);
};

static const std::string litterals[6] = {
	"-inff", "+inff", "nanf",
	"-inf", "+inf", "nan",
};
#endif /* SCALARCONVERTER_HPP */