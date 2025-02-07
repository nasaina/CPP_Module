NAME = megaphone

SRC = megaphone.cpp

CC = c++

FLAGS = -Wall -Werror -Wextra

OBJ	= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@clear
	@echo "\n\e[1;91mCompilation successful\e[0m\n"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -rf *.o

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY : clean fclean re