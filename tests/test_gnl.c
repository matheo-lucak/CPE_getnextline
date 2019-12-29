/*
** EPITECH PROJECT, 2019
** test_init_op
** File description:
** infinadd criterion test
*/

#include <fcntl.h>
#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "get_next_line.h"

char *get_next_line(int fd);

int open_file(char *path)
{
    int fd = open(path, O_RDONLY);

    return (fd);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, str + i, 1);
        i++;
    }
}

void close_file(int fd)
{
    if (fd != 1)
        close(fd);
}

Test(gnl, read_a_line)
{
    int i = 0;
    int fd = open_file("./tests/map");
    char *str = get_next_line(fd);
    char *expected = "J'ai plus de souvenirs que si j'avais mille ans.";

    close_file(fd);
    cr_assert_str_eq(str, expected);
}

Test(gnl, read_a_file)
{
    int i = 0;
    int fd = open_file("./tests/map2");
    char *str = get_next_line(fd);

    cr_redirect_stdout();
    while (str != NULL) {
        my_putstr(str);
        my_putstr("\n");
        str = get_next_line(fd);
    }
    close_file(fd);
    cr_assert_stdout_eq_str("J'ai deja deux chat sur moi\n"\
                            "Pis un troisieme veut venir\n"\
                            "C'est mort\n"\
                            "Il sent pas bon en plus\n");
}

Test(gnl, wrong_fd)
{
    char *expected = "NULL";
    char *str = get_next_line(-1);

    if (str == NULL)
        str = "NULL";
    cr_assert_str_eq(str, expected);
}