NAME = test

SRC = Bureaucrat.cpp Form.cpp Intern.cpp main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

run: all
	./$(NAME)
