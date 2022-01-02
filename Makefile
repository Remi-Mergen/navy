##
## EPITECH PROJECT, 2021
## My_sort_word_array
## File description:
## Makefile
##

SRC	=	$(shell find source/ -name "*.c")

INC	=	-I./include

OBJ	=	$(SRC:.c=.o)

CFLAGS = $(INC) -Wall -Wextra -Wpedantic -ggdb3

NAME	=	navy

all:	$(OBJ)	$(NAME)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(INC)
	@echo -e "\033[01;38;5;10m================ Compiling: Done =======\
	=========\033[0;0m"
	make clean

clean:
	rm -f $(OBJ)
	@echo -e "\x1b[33;01m================  clean: Done =========\
	=======\033[0;0m"

fclean:		clean
	rm -f $(NAME)
	@echo -e "\x1b[33;01m================ fclean: Done ==========\
	======\033[0;0m"

re:			fclean all

exe:	re
	$(shell ./navy Screen_Capture.txt)

.PHONY: re clean fclean all
