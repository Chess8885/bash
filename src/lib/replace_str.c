/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** replace_str
*/

#include "my.h"

char *replace_str(char *str, char c, char c2)
{
    char *new = mystr_trim(str, 0);
    int i = 0;

    if (new == 0)
        return (0);
    while (new[i] != 0) {
        if (new[i] == c)
            new[i] = c2;
        i++;
    }
    return (new);
}
