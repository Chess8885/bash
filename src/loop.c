/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** loop
*/

#include "my.h"

void loop_shell(t_shell *shell)
{
    char *line = 0;
    size_t read = 0;
    int status = 0;
    char *trimmed = 0;

    while (1) {
        write(1, "$>", 2);
        status = getline(&line, &read, stdin);
        if (status == -1 || line <= 0)
            break;
        trimmed = copy_trim(line);
        if (trimmed != 0 && my_strlen(trimmed)
            != 0 && exec_line(shell, trimmed) == -1)
            break;
    }
    if (line != 0)
        free(line);
}
