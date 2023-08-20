#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string & str) {

	// Make parsing
	// check after `.`
	// check after `f`
	// check multiple `.`
	// check after f
	// check after litterals (aka nan, inf, -inf, ...)

	double val;

	try
	{
		val = std::stod(str);
		std::cout << "char: " << toChar(val) << std::endl;
		std::cout << "int: " << toInt(val) << std::endl;
		std::cout << "float: " << toFloat(val) << std::endl;
		std::cout << "double: " << toDouble(val) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible" << std::endl;
		std::cerr << "float: impossible" << std::endl;
		std::cerr << "double: impossible" << std::endl;
		return;
	}
	
}

std::string ScalarConverter::toChar(const double & val) {
	if (val > 127 || val < 0 || std::fmod(val, 1.0)) {
		return "impossible";
	} else if (isprint(val)) {
		return "'" + std::string(1, static_cast<char>(val)) + "'";
	} else {
		return "Non displayable";
	}
}

std::string ScalarConverter::toInt(const double & val) {
	if (
			val < std::numeric_limits<int>::lowest()
		||	val > std::numeric_limits<int>::max() 
		||	std::fmod(val, 1.0)
		||	std::isnan(val)
		||	std::isinf(val)
		) {
		return "impossible";
	} else {
		return std::to_string(static_cast<int>(val));
	}
}

std::string ScalarConverter::toFloat(const double & val) {
	if (std::isinf(val)) {
		return val < 0 ? "-inff" : "+inff";
	} else if (std::isnan(val)) {
		return "nanf";
	}

	if (
			val < std::numeric_limits<float>::lowest()
		||	val > std::numeric_limits<float>::max() 
		) {
		return "impossible";
	} else {
		std::string str = std::to_string(static_cast<float>(val));
		str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
		str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
		if (std::fmod(val, 1.0)) {
			return str + "f";
		} else {
			return str + ".0f";
		}
	}
}

std::string ScalarConverter::toDouble(const double & val) {
	if (std::isinf(val)) {
		return val < 0 ? "-inf" : "+inf";
	} else if (std::isnan(val)) {
		return "nan";
	}
	std::string str = std::to_string(val);
	str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
	str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
	if (std::fmod(val, 1.0)) {
		return str;
	} else {
		return str + ".0";
	}
}

ScalarConverter::ScalarConverter(ScalarConverter & other) { 
	(void)other;
}
ScalarConverter & ScalarConverter::operator=(const ScalarConverter & other) {
	(void)other;
	return *this;
}