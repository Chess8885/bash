/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** mystr_trim
*/

#include "my.h"

char *mystr_trim(char *src, char limiter)
{
    char *tmp = 0;
    int i = 0;

    while (src != 0 && src[i] != 0 && src[i] != limiter) {
        i++;
    }
    if (src[i] == limiter && src[i] != 0) {
        tmp = &src[i + 1];
    }
    if (tmp != 0 && tmp[0] != 0) {
        return (mystr_copy(tmp, 0));
    } else {
        return (mystr_copy(src, 0));
    }
}
