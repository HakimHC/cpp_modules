NAME = magic

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXXFLAGS += -g3

CXXFLAGS += -fsanitize=address

SRC = main.cpp \
      AMateria.cpp \
      Ice.cpp \
      Cure.cpp \
      Character.cpp \
      MateriaSource.cpp \
      TestFont.cpp

OBJ = $(SRC:.cpp=.o)

LDFLAGS = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
