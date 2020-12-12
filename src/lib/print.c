/*
** EPITECH PROJECT, 2019
** print
** File description:
** print
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != 0) {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int my_strlen(const char *str)
{
    int i = 0;

    while (str != 0 && str[i] != 0) {
        i++;
    }
    return (i);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int operation = 0;

    while (i != n - 1 && s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0) {
        i++;
    }
    operation = (s1[i] - s2[i]);
    return (operation);
}

char *my_strcat(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int length = (my_strlen(s1) + my_strlen(s2) + 1);
    char *s3 = malloc(sizeof(char) * length);

    if (s3 == 0) {
        return (0);
    }
    while (s1 != 0 && s1[i] != 0) {
        s3[i] = s1[i];
        i++;
    }
    s3[i] = '\0';
    while (s2 != 0 && s2[j] != 0) {
        s3[i] = s2[j];
        i++;
        j++;
    }
    s3[i] = '\0';
    return (s3);
}
