/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** setenv.c
*/

#include "my.h"

void print_env(t_env *env)
{
    t_env *e = 0;

    e = env;
    while (e != 0) {
        if (e != env) {
            write(1, "\n", 1);
        }
        if (e->key != 0) {
            write(1, e->key, my_strlen(e->key));
            write(1, "=", 1);
            my_putstr(e->data);
        }
        e = e->next;
    }
    write(1, "\n", 1);
}

t_env *pre_setenv(t_shell *shell, char *key, char *data)
{
    t_env *new;

    new = malloc(sizeof(t_env));
    if (new == 0)
        return (0);

    new->key = mystr_trim(key, 0);
    new->data = mystr_trim(data, 0);
    new->next = 0;
    return (new);
}

void my_setenv(t_shell *shell, char *key, char *data)
{
    t_env *tmp = shell->env;

    if (tmp == 0) {
        shell->env = pre_setenv(shell, key, data);
        return;
    }
    while (1) {
        if (my_strlen(key) == my_strlen(tmp->key) &&
            my_strncmp(key, tmp->key, my_strlen(key)) == 0) {
            tmp->data = mystr_trim(data, 0);
            return;
        }
        if (tmp->next == 0)
            break;
        tmp = tmp->next;
    }
    tmp->next = pre_setenv(shell, key, data);;
}

void my_unsetenv(t_shell *shell, char *key)
{
    t_env *tmp = shell->env;
    t_env *tmp_prev = 0;

    if (my_strlen(key) == my_strlen(tmp->key) &&
        my_strncmp(key, tmp->key, my_strlen(key)) == 0) {
        shell->env = tmp->next;
        return;
    }
    tmp_prev = tmp;
    tmp = tmp->next;
    while (tmp != 0) {
        if (my_strlen(key) == my_strlen(tmp->key) &&
            my_strncmp(key, tmp->key, my_strlen(key)) == 0) {
            tmp_prev->next = tmp->next;
            return;
        }
        tmp_prev = tmp;
        tmp = tmp->next;
    }
}
