NAME = main
SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ = $(SRC:%.cpp=%.o)
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -c -std=c++98

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all