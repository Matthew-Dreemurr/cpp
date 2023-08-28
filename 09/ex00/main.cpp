#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char *av[])
{
    if (ac != 3)
    {
        std::cerr << "Usage: ./bitcoin [filename] [filename]" << std::endl;
        return 1;
    }
    BitcoinExchange bce;
    try
    {
        std::cout << "Reading database..." << std::endl;
        bce.readDb(av[1]);
        std::cout << "\n[====================]\n" << std::endl;
        std::cout << "Reading input file..." << std::endl;
        bce.readInputFile(av[2]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
    return 0;
}