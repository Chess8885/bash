/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** darray_free
*/

#include "my.h"

void darray_free(char **src)
{
    int i = 0;

    if (src != 0) {
        while (src[i] != 0) {
            free(src[i]);
            i++;
        }
        free(src);
    }
}
