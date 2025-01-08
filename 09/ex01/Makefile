NAME	= RPN

CC		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98

OBJDIR = .obj

FILES = main\
		RPN

OBJ = $(addprefix $(OBJDIR)/, $(FILES:=.o))

HEADER_FILES = RPN.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER_FILES)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER_FILES)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re