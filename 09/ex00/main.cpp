#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./bitcoin [filename]" << std::endl;
        return 1;
    }
    BitcoinExchange bce;
    try
    {
        bce.readDb(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
    return 0;
}