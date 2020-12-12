/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** darray_empty
*/

#include "my.h"

char **darray_empty(void)
{
    char **new;

    new = malloc(sizeof(char *) * 1);
    if (new == 0) {
        return (0);
    }
    new[0] = 0;
    return (new);
}
