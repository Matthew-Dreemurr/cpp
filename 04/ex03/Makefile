NAME = test

SRC = AMateria/AMateria.cpp Character/Character.cpp Cure/Cure.cpp Ice/Ice.cpp MateriaSource/MateriaSource.cpp main.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

run: all
	./$(NAME)
