/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** internal
*/

#include "my.h"

int is_internal(char *bin)
{
    if (my_strncmp("exit", bin, my_strlen(bin)) == 0)
        return (1);
    if (my_strncmp("env", bin, my_strlen(bin)) == 0)
        return (1);
    if (my_strncmp("cd", bin, my_strlen(bin)) == 0)
        return (1);
    if (my_strncmp("setenv", bin, my_strlen(bin)) == 0)
        return (1);
    if (my_strncmp("unsetenv", bin, my_strlen(bin)) == 0)
        return (1);
    return (0);
}

void check_cd(char *bin, char **args, t_shell *shell)
{
    if (my_strncmp("cd", bin, my_strlen(bin)) == 0) {
        if (darray_length(args) == 0) {
        } else if (darray_length(args) >= 1) {
            if (chdir(args[0]) < 0) {
                my_putstr("cd: ");
                my_putstr(args[0]);
                my_putstr(": No such file or directory\n");
            }
        }
    }
}

void check_setenv(char *bin, char **args, t_shell *shell)
{
    if (my_strncmp("setenv", bin, my_strlen(bin)) == 0) {
        if (darray_length(args) == 2) {
            my_setenv(shell, args[0], args[1]);
        } else {
            my_putstr("setenv: wrong usage\n");
        }
    }
}

void check_unsetenv(char *bin, char **args, t_shell *shell)
{
    if (my_strncmp("unsetenv", bin, my_strlen(bin)) == 0) {
        if (darray_length(args) == 1) {
            if (shell != 0 && shell->env != 0) {
                my_unsetenv(shell, args[0]);
            }
        } else {
            my_putstr("unsetenv: wrong usage\n");
        }
    }
}

int run_internal(char *bin, char **args, t_shell *shell)
{
    if (my_strncmp("exit", bin, my_strlen(bin)) == 0)
        return (-1);
    if (my_strncmp("env", bin, my_strlen(bin)) == 0) {
        print_env(shell->env);
    }
    check_cd(bin, args, shell);
    check_setenv(bin, args, shell);
    check_unsetenv(bin, args, shell);
    return (0);
}
