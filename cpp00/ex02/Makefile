NAME = accounting

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

LDFLAGS = -fsanitize=address

SRC = tests.cpp \
      Account.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
