/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** env
*/

#include "my.h"

char *env_key(char *entry)
{
    return (mystr_copy(entry, '='));
}

void add_new_env(t_env *env, char *entry)
{
    t_env *tmp = env;

    while (tmp->next != 0) {
        tmp = tmp->next;
    }
    tmp->next = new_env(entry);
}

t_env *new_env(char *entry)
{
    t_env *new;

    new = malloc(sizeof(t_env));
    if (new == 0)
        return (0);
    new->next = 0;
    new->key = env_key(entry);
    new->data = mystr_trim(entry, '=');
    return (new);
}

t_env *get_env(char **env)
{
    int i = 0;
    t_env *new = 0;

    if (env == 0)
        return (0);
    while (env[i] != 0) {
        if (new == 0) {
            new = new_env(env[i]);
        } else {
            add_new_env(new, env[i]);
        }
        i++;
    }
    return (new);
}
