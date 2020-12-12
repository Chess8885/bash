/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** error_message
*/

#include "my.h"

void error_message(void)
{
    write(1, &"command not found\n", 18);
}
