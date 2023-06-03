NAME = accounting

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

CFLAGS += -g3

LDFLAGS = -fsanitize=address

SRC = tests.cpp \
      Account.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
