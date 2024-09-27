NAME = megaphone

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:.c=.o)

all = $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) megaphone.cpp -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(SRC) -c $< -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: clean all

.PHONY = all clean re