#include <stack>
#include <cctype>

int main(int ac, char **av)
{
    std::stack<int> s;

    for (int i = 0; i < ac; i++) {
        if (!std::isdigit(av[i][0]) && av[i][1] == '\0') {
            std::cout << "Error: " << av[i] << " is not a number" << std::endl;
            return (1);
        }
    }
    return (0);
}