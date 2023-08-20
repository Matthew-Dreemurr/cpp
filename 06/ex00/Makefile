NAME = test

SRC = ScalarConverter.cpp main.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

run: all
	./$(NAME)
