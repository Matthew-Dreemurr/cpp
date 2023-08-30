#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2 || av[1][0] == '\0') {
        printf("Error\n");
        return (1);
    }

    std::stack<long> s;
    std::string args(av[1]);
    std::stringstream ss(args);

    std::string arg;
    while (std::getline(ss, arg, ' ')) {
        // Check if the string as only one char
        if (arg.size() != 1) {
            std::cout << "Error" << std::endl; 
            return (1);
        }

        const char c = arg[0];

        // Check if the char is a digit
        if (std::isdigit(c)) {
            s.push(c - '0');
            continue;
        }

        const char op[] = "+-*/";
        const char *o = std::strchr(op, c);

        // Check if the char is an operator
        if (!o) {
            printf("Error\n");
            return (1);
        }

        if (s.size() < 2) {
            std::cout << "Not enough values in the stack" << std::endl;
            return (1);
        }

        const long b = s.top();
        s.pop();
        const long a = s.top();
        s.pop();

        if (*o == '+') {
            s.push(a + b);
        } else if (*o == '-') {
            s.push(a - b);
        } else if (*o == '*') {
            s.push(a * b);
        } else if (*o == '/') {
            if (b == 0) {
                std::cout << "Error: Division by zero" << std::endl;
                return (1);
            }
            s.push(a / b);
        }
    }
    std::cout << s.top() << std::endl;
    return (0);
}