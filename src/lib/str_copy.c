/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** str_copy
*/

#include "my.h"

char *str_copy(char *src)
{
    char *new;
    int i = 0;

    new = malloc(sizeof(src) * my_strlen(src));
    if (new <= 0) {
        return (0);
    }
    while (src[i] != 0) {
        new[i] = src[i];
        i++;
    }
    new[i] = 0;
    return (new);
}
