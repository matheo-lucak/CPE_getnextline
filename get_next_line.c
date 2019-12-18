/*
** EPITECH PROJECT, 2019
** get_map
** File description:
** get_map func
*/

#include "get_next_line.h"

int is_end_of_line(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *my_strdup_line(char *line, char *buffer)
{
    int i = 0;
    int j = 0;

    while (buffer[i] != '\0' && buffer[i] != '\n')
        i++;
    line = malloc(sizeof(char) * (i + 1));
    if (line == NULL)
        return (NULL);
    while (j < i) {
        line[j] = buffer[j];
        j++;
    }
    line[j] = '\0';
    return (line);
}

char *re_alloc_buffer(char *buffer, char *stock, int mode)
{
    char *new_buffer = NULL;
    int buffer_size = -1;
    int j = -1;

    while (buffer[++buffer_size] != '\0' && mode == 1);
    new_buffer = malloc(sizeof(char) * (buffer_size + READ_SIZE + 1));
    if (new_buffer == NULL)
        return (NULL);
    while (++j < buffer_size && mode == 1)
        new_buffer[j] = buffer[j];
    j = -1;
    while (stock[++j] != '\0')
        new_buffer[j + buffer_size] = stock[j];
    new_buffer[j + buffer_size] = '\0';
    free(buffer);
    return (new_buffer);
}

char *add_in_buffer(int fd, char *buffer, int *rd)
{
    char stock[READ_SIZE + 1];

    if (stock == NULL)
        return (NULL);
    while (!is_end_of_line(buffer) && *rd != 0) {
        *rd = read(fd, stock, READ_SIZE);
        if (*rd == -1)
            return (NULL);
        stock[*rd] = '\0';
        buffer = re_alloc_buffer(buffer, stock, 1);
    }
    return (buffer);
}

char *get_next_line(int fd)
{
    static char *buffer = NULL;
    char * line = NULL;
    int i = -1;
    int rd = -1;

    if (fd == -1)
        return (NULL);
    if (buffer == NULL) {
        buffer = malloc(sizeof(char) * (READ_SIZE + 1));
        buffer[0] = '\0';
    }
    buffer = add_in_buffer(fd, buffer, &rd);
    if (buffer == NULL || (buffer[0] == '\0' && rd == 0))
        return (NULL);
    line = my_strdup_line(line, buffer);
    while (line[++i] != '\0' && line[i] != '\n');
    buffer = re_alloc_buffer(buffer, buffer + i + 1, 0);
    if (line == NULL)
        return (NULL);
    return (line);
}