NAME = ex01

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp \
      Bureaucrat.cpp \
      AForm.cpp \
      ShrubberyCreationForm.cpp \
      PresidentialPardonForm.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
