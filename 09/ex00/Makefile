NAME	= btc

CC		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98

OBJDIR = .obj

FILES = main\
		BitcoinExchange\

SRC = main.cpp\

OBJ = $(addprefix $(OBJDIR)/, $(FILES:=.o))

HEADER_FILES = BitcoinExchange.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER_FILES)
	$(CC) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re