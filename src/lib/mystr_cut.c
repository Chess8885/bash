/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** mystr_cut
*/

#include "my.h"

char **mystr_cut(char *src, char limiter)
{
    return (my_str_to_word_array(src, limiter));
}
