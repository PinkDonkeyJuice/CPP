NAME	= Zombie

CC		= c++
FLAGS	= -Wall -Werror -Wextra

OBJDIR = .obj

FILES = main\
	Zombie\
	zombieHorde\

SRC = $(FILES:=.cpp);
OBJ = $(addprefix $(OBJDIR)/, $(FILES:=.o))

HEADER	= Zombie.hpp\

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all