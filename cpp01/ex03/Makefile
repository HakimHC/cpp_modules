NAME = ex03

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

LDFLAGS = -fsanitize=address

SRC = main.cpp \
      Weapon.cpp \
      HumanA.cpp \
      HumanB.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
