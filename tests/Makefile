##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make file for test run
##

CC      	=	gcc

SRC     	=	test_gnl.c	\
				../get_next_line.c	\

OBJ			=	$(SRC:.c=.o)

NAME		=	unit_tests

CFLAGS		=	--coverage -I./../

LDLIBS		=	-lcriterion -lgcov

all:			fclean $(NAME)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(LDLIBS)
clean:
				rm -f $(OBJ)
				rm -f *.gc*
				rm -f ../*.gc*

fclean: 		clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			$(NAME) all clean fclean re
