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
        _data = copy._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

int BitcoinExchange::_dateToInt(int raw_date[3]) {
    // Check for invalid date
    int day_max[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (raw_date[MONTH] < 1 || raw_date[MONTH] > 12)
        throw Exception("Invalid month");
    if (raw_date[YEAR] % 4 == 0 && (raw_date[YEAR] % 100 != 0 || raw_date[YEAR] % 400 == 0))
        day_max[1] = 29;
    if (raw_date[DAY] < 1 || raw_date[DAY] > day_max[raw_date[MONTH] - 1])
        throw Exception("Invalid day");
 
    return raw_date[YEAR] * 10000 + raw_date[MONTH] * 100 + raw_date[DAY];
}

float BitcoinExchange::_getClosetDatePrice(int date) {
    std::map<int, float>::iterator it = _data.end();

    it--;

    for (;;it--) {
        if (it->first <= date) {
            return it->second;
        }
        if (it == _data.begin()) {
            break;
        }
    }
    throw Exception("No data found");
}

void BitcoinExchange::_storeDatePrice(int raw_date[3], float price) {
   
    const int date = _dateToInt(raw_date);

    // Check for duplicate date    
    if (_data.find(date) != _data.end())
        throw Exception("Duplicate date");
    
    // Check for invalid price
    if (std::isnan(price) || std::isinf(price) || price < 0 || price > 10000)
        throw Exception("Invalid price");
    
    // Store date and price
    _data[date] = price;
}

void BitcoinExchange::readDb(std::string filename)
{
    // Check filename
    if (filename.empty())
        throw Exception("Error: Filename is empty");

    // Open file
    _file.open(filename.c_str(), std::ios::in);

    // Check if file successfully opened and not empty
    if (!_file.is_open())
        throw Exception("Error: File does not exist");
    if (_file.peek() == std::ifstream::traits_type::eof())
        throw Exception("Error: File is empty");

    // Read header of csv file
    if (!_file.eof())
    {
        std::string line;
        std::getline(_file, line);
        if (_file.eof())
            throw Exception("Error: File is empty");
        if (line != "date,exchange_rate")
            throw Exception("Error: Invalid header");
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

        // Read format: "year-month-day,price"
        const int ret = std::sscanf(line.c_str(), "%d-%d-%d,%f", &raw_date[YEAR], &raw_date[MONTH], &raw_date[DAY], &price);
        if (ret == EOF) {
            if  (_file.eof())
                break;
            throw Exception("Error: Read faild: " + filename + ":" + INT_TO_STR(line_count));
        }
        if (ret != 4) {
            std::cout << "Warn: Invalid " << args[ret] << " format, value will be ignored: " << filename << ":" << INT_TO_STR(line_count) << std::endl;
            continue;
        }

        // Store date and price
        try {
            _storeDatePrice(raw_date, price);
        } catch (const std::exception &e) {
            std::cout << "Warn: " << std::string(e.what()) << " format, value will be ignored: " << filename << ":" << INT_TO_STR(line_count) << std::endl;
        }
    }

    // Close file
    try {
        _file.close();
    } catch (const std::exception &e) {
        std::cout << "Error: " << std::string(e.what()) << " " << filename << std::endl;
    }

    std::cout << "Info: " << filename << " successfully read" << std::endl;
    std::cout << "Info: " << _data.size() << " entries stored" << std::endl;
}


float BitcoinExchange::_convertPriceRate(int raw_date[3], float price) {
    // Check for invalid price
    if (std::isnan(price) || std::isinf(price))
        throw Exception("Invalid price");
    if (price < 0)
        throw Exception("Not a positive price");
    if (price > 1000)
        throw Exception("Price too high");

   return  _getClosetDatePrice(_dateToInt(raw_date));
}

void BitcoinExchange::readInputFile(std::string filename)
{
    if (_data.empty())
        throw Exception("Error: No data stored");
    // Check filename
    if (filename.empty())
        throw Exception("Error: Filename is empty");

    // Open file
    _file.open(filename.c_str(), std::ios::in);

    // Check if file successfully opened and not empty
    if (!_file.is_open())
        throw Exception("Error: File does not exist");
    if (_file.peek() == std::ifstream::traits_type::eof())
        throw Exception("Error: File is empty");

    // Read header of csv file
    if (!_file.eof())
    {
        std::string line;
        std::getline(_file, line);
        if (_file.eof())
            throw Exception("Error: File is empty");
        if (line != "date | value")
            throw Exception("Error: Invalid header, fist line should be \"date | value\"");
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

        // Read format: "year-month-day,price"
        const int ret = std::sscanf(line.c_str(), "%d-%d-%d | %f", &raw_date[YEAR], &raw_date[MONTH], &raw_date[DAY], &price);
        if (ret == EOF) {
            if  (_file.eof())
                break;
            std::cout << "Warn: Invalid line: " << filename << ":" << INT_TO_STR(line_count) << std::endl;
            continue;
        }
        if (ret != 4) {
            std::cout << "Warn: Invalid " << args[ret] << " format, value will be ignored: " << filename << ":" << INT_TO_STR(line_count) << std::endl;
            continue;
        }

        // Store date and price
        try {
            float priceRate = _convertPriceRate(raw_date, price);
            std::cout << raw_date[0] << "-" << raw_date[1] << "-" << raw_date[2] << " => " << price << " = " << priceRate * price << std::endl;
        } catch (const std::exception &e) {
            std::cout << "Warn: " << std::string(e.what()) << ", value will be ignored: " << filename << ":" << INT_TO_STR(line_count) << std::endl;
        }
    }

    // Close file
    try {
        _file.close();
    } catch (const std::exception &e) {
        std::cout << "Error: " << std::string(e.what()) << " " << filename << std::endl;
    }
}