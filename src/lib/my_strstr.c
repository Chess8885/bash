/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** my_strstr.c
*/

#include "my.h"

int my_strstr_continue(char *s1, char *s2, int i)
{
    if (s1[i] < s2[i]) {
        return (-1);
    }
    else if (s1[i] > s2[i]) {
        return (1);
    } else
        return (0);
}

int my_strstr(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != 0) {
        if (s1[i] < s2[i]) {
            return (-1);
        }
        else if (s1[i] > s2[i]) {
            return (1);
        } else {
            return (0);
        }
        i++;
    }
    j = my_strstr_continue(s1, s2, i);
    return (j);
}
