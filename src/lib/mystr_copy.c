/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** mystr_copy
*/

#include "my.h"

char *mystr_copy(char *src, char stop_char)
{
    char *new;
    int i = 0;

    new = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (new <= 0)
        return (0);
    while (src[i] != 0 && src[i] != stop_char) {
        new[i] = src[i];
        i++;
    }
    new[i] = 0;
    return (new);
}
