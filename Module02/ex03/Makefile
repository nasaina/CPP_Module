NAME = Bsp

CC = g++

FLAGS = -Wall -Werror -Wextra -g -std=c++98

SRC = Fixed.cpp bsp.cpp Point.cpp main.cpp

OBJ	= $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@clear
	@echo "\n\e[1;91mCompilation successful\e[0m\n"

%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean	:
	@rm -rf *.o

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY : clean fclean re
