#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <sstream>

#define INT_TO_STR(x) static_cast<std::ostringstream &>(std::ostringstream() << x).str()

enum Date
{
    YEAR = 0,
    MONTH = 1,
    DAY = 2
};

class BitcoinExchange
{
private:
    std::map<int, float> _data;
    std::ifstream _file;

    void _storeDatePrice(int[], float);
    int _dateToInt(int[]);
    float _getClosetDatePrice(int);
    float _convertPriceRate(int[], float);
public:
    BitcoinExchange(/* args */);
    BitcoinExchange(const BitcoinExchange &);
    BitcoinExchange &operator=(const BitcoinExchange &);
    ~BitcoinExchange();

    void readDb(std::string filename);
    void readInputFile(std::string filename);

    class Exception : public std::runtime_error
    {
    public:
        Exception(std::string const &msg) : std::runtime_error(msg) {}
    };
};



#endif /* BITCOINEXCHANGE_HPP */
