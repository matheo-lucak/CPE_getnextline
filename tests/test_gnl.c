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

int fd = -1;

void open_file(void)
{
    fd = open("tests/map", O_RDONLY);
    cr_redirect_stdout();
}

void close_file(void)
{
    if (fd != 1)
        close(fd);
}

Test(gnl, read_a_line, .init = open_file, .fini = close_file)
{
    char *expected = " J'ai plus de souvenirs que si j'avais mille ans.";
    char *got = get_next_line(fd);

    cr_assert_str_eq(got, expected);
}
