NAME = phonebook

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra

CXXFLAGS += -std=c++98

LDFLAGS = -fsanitize=address

SRC = main.cpp \
      Contact.cpp \
      PhoneBook.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
