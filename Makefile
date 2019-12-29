##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make file for test run
##

CC      	=	gcc

SRC     	=	./tests/test_gnl.c	\
				get_next_line.c

NAME		=	./unit_tests

CFLAGS		=	--coverage -I./

LDLIBS		=	-lcriterion -lgcov

all:			fclean $(NAME)

$(NAME):
				$(CC) -o $(NAME) $(SRC) $(LDLIBS) $(CFLAGS)
				./$(NAME)
				mv test*.gc* ./tests
clean:
				rm -f $(OBJ)

fclean: 		clean
				rm -f $(NAME)
				rm -f *.gc*
				rm -f ./tests/*.gc*

re:				fclean all

.PHONY:			$(NAME) all clean fclean re
