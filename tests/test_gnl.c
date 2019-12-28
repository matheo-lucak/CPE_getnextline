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

Test(gnl, incorrect_file)
{
    int fd = open("tests/map", O_RDONLY);
    char *got = get_next_line(fd);
    char *expected = " J'ai plus de souvenirs que si j'avais mille ans.";

    if (fd == -1)
        return ;
    cr_assert_str_eq(got, expected);
    if (fd != -1)
        close(fd);
}
