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

int open_file(void)
{
    int fd = open("tests/map", O_RDONLY);

    return (fd);
}

void close_file(int fd)
{
    if (fd != 1)
        close(fd);
}

Test(gnl, read_a_line)
{
    int fd = open_file();
    char *got = get_next_line(fd);
    char *expected = " J'ai plus de souvenirs que si j'avais mille ans.";

    close_file(fd);
    cr_assert_str_eq(got, expected);
}
