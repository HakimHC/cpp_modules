NAME = type

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

LDFLAGS = -fsanitize=address

SRC = main.cpp \
      Base.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:: fclean
re:: all

.PHONY: all clean fclean re
