#Name of the executable
NAME 		= btc

#Compiler flags
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98

CXXFLAGS 	+= -g3

#Source files
SRC		= main.cpp \
		  BitcoinExchange.cpp

#Object files
OBJ 		= $(SRC:.cpp=.o)

#Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:: fclean
re:: all

asan: CXXFLAGS 	+= -fsanitize=address
asan: CXXFLAGS 	+= -O1
asan: LDFLAGS 	+= -fsanitize=address
asan: re

.PHONY: all clean fclean re asan
