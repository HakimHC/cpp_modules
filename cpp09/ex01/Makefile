#Name of the executable
NAME 		= RPN

#Compiler flags
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98

CXXFLAGS 	+= -fsanitize=address

CXXFLAGS 	+= -g3

#Linker flags
LDFLAGS 	= -fsanitize=address

#Source files
SRC 		= main.cpp \
		  RPN.cpp

#Compiled object files
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

.PHONY: all clean fclean re
