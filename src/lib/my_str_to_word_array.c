/*
** EPITECH PROJECT, 2019
** my_function
** File description:
** my_function
*/

#include "my.h"

int words_counter(char *str, char c)
{
    int i = 0;
    int j = 1;

    while (str[i] != 0 && str[i] != 10) {
        if (str[i] == c && str[i + 1] != 0 && str[i + 1] != c) {
            j++;
        }
        i++;
    }
    return (j);
}

int chars_counter(char *str, char c)
{
    int i = 0;

    while ((str[i] != c) && (str[i] != 0) && (str[i] != 10)) {
        i++;
    }
    return (i);
}

void my_str_to_word_array_replace(char *str, char c, char **tab, int length)
{
    int i = 0;

    while (i < length) {
        if (str[i] == c) {
            str[i] = 0;
        }
        i++;
    }
}

char **my_str_to_word_array_next(char *str, char c, char **tab)
{
    int length = my_strlen(str);
    int i = 0;
    int j = 0;

    tab[j] = 0;
    while (i < length) {
        if (i == 0 && str[i] != 0) {
            tab[0] = &str[0];
            j = 1;
        }
        if (i != 0 && str[i - 1] == c && str[i] != c) {
            str[i - 1] = 0;
            tab[j] = &str[i];
            j++;
        }
        i++;
    }
    tab[j] = 0;
    return (tab);
}

char **my_str_to_word_array(char *str, char c)
{
    char **tab = 0;
    int length = my_strlen(str);
    int i = 0;
    int words = 0;

    str = mystr_trim(str, 0);
    while (str != 0 && str[i] != 0) {
        if (i == 0 && str[i] != c) {
            words++;
        }
        if (i != 0 && str[i - 1] == c && str[i] != c) {
            words++;
        }
        i++;
    }
    tab = malloc(sizeof(char *) * (words + 2));
    my_str_to_word_array_next(str, c, tab);
    my_str_to_word_array_replace(str, c, tab, length);
    return (tab);
}
