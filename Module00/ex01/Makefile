NAME = contact

CC = c++

FLAGS = -Wall -Werror -Wextra -g -std=c++98

OBJ	= $(SRC:.c=.o)

SRC = Contact.cpp main.cpp PhoneBook.cpp

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@clear
	@echo "\n\e[1;91mCompilation successful\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean	:
	@rm -rf *.o

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY : clean fclean re
