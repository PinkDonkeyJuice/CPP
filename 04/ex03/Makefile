NAME	= Materia

CC		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98

OBJDIR = .obj

SRC_DIR = src

HEADER_DIR = include

CLASS_FILES = AMateria\
			Ice\
			Cure\
			Character\
			MateriaSource\


SRC_FILES = $(addprefix $(SRC_DIR)/, $(CLASS_FILES))\
		$(SRC_DIR)/main\

SRC = $(SRC_FILES:=.cpp)
OBJ = $(addprefix $(OBJDIR)/, $(notdir $(SRC_FILES:=.o)))

HEADER_FILES = $(addprefix $(HEADER_DIR)/, $(CLASS_FILES:=.hpp))\
				$(HEADER_DIR)/ICharacter.hpp\
				$(HEADER_DIR)/IMateriaSource.hpp\

all: $(NAME)

$(NAME): $(OBJ) $(HEADER_FILES)
	$(CC) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER_FILES)
	@mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re