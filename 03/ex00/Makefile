NAME = claptrap

SRC = ClapTrap.cpp main.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

run: all
	./$(NAME)
