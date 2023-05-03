NAME = HarlFilter

SRC = harlfilter.cpp main.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

run: all
	./HarlFilter