NAME = zombo

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp \
      Zombie.cpp \
      newZombie.cpp \
      randomChump.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
