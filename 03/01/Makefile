NAME = test

SRC = ClapTrap.cpp ClapTrap.hpp main.cpp ScravTrap.cpp ScravTrap.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

run: all
	./$(NAME)
