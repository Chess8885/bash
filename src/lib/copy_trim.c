/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** copy_trim
*/

#include "my.h"

char *copy_trim(char *str)
{
    char *input = 0;
    char *trimmed = 0;

    input = mystr_copy(str, '\n');
    if (input == 0)
        return (0);
    trimmed = trim(input);
    free(input);
    return (trimmed);
}
