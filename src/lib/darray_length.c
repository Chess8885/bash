/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** darray_length
*/

#include "my.h"

int darray_length(char **src)
{
    int length = 0;

    while (src != 0 && src[length] != 0) {
        length++;
    }
    return (length);
}
