NAME = animal

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

CXXFLAGS += -g3

SRC = main.cpp \
      Animal.cpp \
      Dog.cpp \
      Cat.cpp \
      WrongAnimal.cpp \
      WrongCat.cpp

LDFLAGS = -fsanitize=address

OBJ = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
