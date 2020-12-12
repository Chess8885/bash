/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** darray_copy
*/

#include "my.h"

char **darray_copy(char **src)
{
    char **new;
    int i = 0;

    new = malloc(sizeof(char *) * (darray_length(src) + 1));
    if (new <= 0) {
        return (0);
    }
    while (i < darray_length(src)) {
        new[i] = str_copy(src[i]);
        i++;
    }
    new[i] = 0;
    return (new);
}
