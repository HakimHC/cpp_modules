NAME = ex03

CC = c++

CFLAGS = -Wall -Werror -Wextra

CFLAGS += -std=c++98

LDFLAGS = -fsanitize=leak

SRC = main.cpp \
      Weapon.cpp \
      HumanA.cpp \
      HumanB.cpp

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
