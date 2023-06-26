NAME = dmt

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow

SRC = main.cpp \
      ClapTrap.cpp \
      ScavTrap.cpp \
      FragTrap.cpp \
      DiamondTrap.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
