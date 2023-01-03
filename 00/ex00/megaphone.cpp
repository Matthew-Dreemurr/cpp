//
// Created by fluffy on 1/3/23.
//

#include <iostream>

int main(int argc, const char *argv[])
{
    (void)argv;
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }

    for (int i = 1; i < argc; i++) {
        for (int x = 0; argv[i][x]; x++)
        std::cout << (char)std::toupper(argv[i][x]);
    }
    std::cout << "\n";
    return (0);
}