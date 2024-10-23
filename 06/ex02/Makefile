NAME	= identify

CC		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98

OBJDIR = .obj

CLASS_FILES = Base\
	A\
	B\
	C\

FILES = Base\
		main\

SRC = main.cpp\
	Base.cpp\

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