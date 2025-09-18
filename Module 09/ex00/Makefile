NAME = btc

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp BitcoinExchange.cpp

OBJ	= $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@clear
	@echo "\n\e[1;91mExecute the program with \e[0m./"$(NAME)" filename\n"

%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean	:
	@rm -rf $(OBJ)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY : clean fclean re