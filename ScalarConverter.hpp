#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
    public:
        void convert(const std::string & str);

        std::string & toChar(const std::string & str);
        std::string & toInt(const std::string & str);
        std::string & toFloat(const std::string & str);
        std::string & toDouble(const std::string & str);

};

#endif /* SCALARCONVERTER_HPP */