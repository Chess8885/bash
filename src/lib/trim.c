/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** trim
*/

#include "my.h"

char *trim(char *str)
{
    char *replace;
    char **new;
    char *final;

    if (str == 0)
        return (0);
    replace = replace_str(str, '\t', ' ');
    if (replace == 0)
        return (0);
    new = my_str_to_word_array(replace, ' ');
    if (new == 0)
        return (0);
    final = join(new, ' ');
    free(new);
    free(replace);
    return (final);
}
