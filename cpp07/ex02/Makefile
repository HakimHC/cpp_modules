NAME = array

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

asan: CXXFLAGS += -fsanitize=address
asan: LDFLAGS += -fsanitize=address
asan: re

re:: fclean
re:: all

.PHONY: all clean fclean re
