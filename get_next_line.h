/*
** EPITECH PROJECT, 2019
** duck_hunth
** File description:
** header for duck hunt
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <unistd.h>
#include <stdlib.h>

#ifndef READ_SIZE
#define READ_SIZE (1234)
#endif

char *get_next_line(int fd);

#endif /* !GET_NEXT_LINE_H_ */
