NAME = sed

TNAME = tester

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = sed.cpp \
      main.cpp

OBJ = $(SRC:.cpp=.o)

TST = tests.cpp

TOBJ = $(TST:.cpp=.o)

RM = rm -f

all: $(NAME) $(TNAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(TNAME): $(NAME) $(TOBJ)
	$(CXX) $(CFLAGS) $(TOBJ) -o $(TNAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(TOBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TNAME)

re: fclean all

.PHONY: all clean fclean re
