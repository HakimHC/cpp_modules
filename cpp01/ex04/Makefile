NAME = sed

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

# CFLAGS += -fsanitize=address -g3

# LDFLAGS = -fsanitize=address

SRC = sed.cpp \
      main.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
