#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
    {
        // copy data
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::_storeDatePrice(int raw_date[3], float price) {

    // Check for invalid date
    if (raw_date[0] < 1 || raw_date[2] > 31)
        throw Exception("Invalid day");
    if (raw_date[1] < 1 || raw_date[1] > 12)
        throw Exception("Invalid month");
    
    const int date = raw_date[0] * 10000 + raw_date[1] * 1000 + raw_date[2];

    // Check for duplicate date    
    if (_data.find(date) != _data.end())
        throw Exception("Duplicate date");
    
    // Check for invalid price
    if (std::isnan(price) || std::isinf(price) || price < 0 || price > 10000)
        throw Exception("Invalid price");
    
    // Store date and price
    _data[date] = price;
    std::cout << "Debug: " << date << " " << _data[date] << std::endl;
}

void BitcoinExchange::readDb(std::string filename)
{
    // Check filename
    if (filename.empty())
        throw Exception("Filename is empty");

    // Open file
    _file.open(filename.c_str(), std::ios::in);

    // Check if file successfully opened and not empty
    if (!_file.is_open())
        throw Exception("File does not exist");
    if (_file.peek() == std::ifstream::traits_type::eof())
        throw Exception("File is empty");

    // Read header of csv file
    if (!_file.eof())
    {
        std::string line;
        std::getline(_file, line);
        if (_file.eof())
            throw Exception("File is empty");
        if (line != "date,exchange_rate")
            throw Exception("Invalid header");
    }
  
    int line_count = 1;
    const char *args[] = {"year", "month", "day", "price", NULL};

    // Read csv file
    while (!_file.eof())
    {
        line_count++;
        std::string line;
        float       price;
        int         raw_date[3];

        std::getline(_file, line);
        if (_file.eof())
            break;

        // Read format: "year-month-day,price"
        const int ret = std::sscanf(line.c_str(), "%d-%d-%d,%f", &raw_date[0], &raw_date[1], &raw_date[2], &price);
        if (ret == EOF)
            throw Exception("Error: Read faild: " + filename + ":" + INT_TO_STR(line_count));
        if (ret != 4)
            throw Exception("Error: Invalid " + std::string(args[ret]) + " format: " + filename + ":" + INT_TO_STR(line_count));

        // Store date and price
        try {
            _storeDatePrice(raw_date, price);
        } catch (const std::exception &e) {
            throw Exception("Error: " + std::string(e.what()) + " " + filename + ":" + INT_TO_STR(line_count));
        }
    }
    
    throw Exception("end debug");
}