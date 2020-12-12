/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** free_shell
*/

#include "my.h"

void free_shell(t_shell *shell)
{
    t_env *tmp;
    t_env *old;

    if (shell->env != 0) {
        tmp = shell->env;
        while (tmp != 0) {
            old = tmp;
            tmp = tmp->next;
            if (old->key != 0)
                free(old->key);
            if (old->data != 0) {
            }
            free(old);
        }
    }
}
