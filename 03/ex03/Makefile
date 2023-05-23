NAME = test

SRC = ClapTrap.cpp DiamondTrap.cpp FragTrap.cpp main.cpp ScavTrap.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow -g3

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

run: all
	./$(NAME)
