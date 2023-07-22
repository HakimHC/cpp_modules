NAME = ex02

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp \
      Bureaucrat.cpp \
      AForm.cpp \
      ShrubberyCreationForm.cpp \
      PresidentialPardonForm.cpp \
      RobotomyRequestForm.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

asan: CXXFLAGS += -fsanitize=address -g3
asan: LDFLAGS += -fsanitize=address
asan: re

.PHONY: all clean fclean re
