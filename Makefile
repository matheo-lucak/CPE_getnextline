##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

tests_run:
	make -C ./tests/
	./tests/unit_tests

clean:
	rm -f *.o
	make clean -C ./tests/

fclean: clean
	make fclean -C ./tests

re:	fclean all

.PHONY:	$(NAME) all clean fclean
