NAME	= Animal

CC		= c++
FLAGS	= -Wall -Werror -Wextra

OBJDIR = .obj

CLASS_FILES = Animal\
		Dog\
		Cat\
		WrongAnimal\
		WrongCat\

FILES = $(CLASS_FILES)\
		main\

SRC = $(FILES:=.cpp);
OBJ = $(addprefix $(OBJDIR)/, $(FILES:=.o))

HEADER_FILES = $(CLASS_FILES:=.hpp)

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