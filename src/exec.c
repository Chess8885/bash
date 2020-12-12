/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** join
*/

#include "my.h"

t_env *env_findkey(t_env *env, char *key)
{
    t_env *tmp = 0;

    tmp = env;
    while (tmp != 0) {
        if (my_strncmp(tmp->key, key, my_strlen(key)) == 0) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return (0);
}

int env_size(t_env *env)
{
    int size = 0;
    t_env *tmp = 0;

    tmp = env;
    while (tmp != 0) {
        tmp = tmp->next;
        size++;
    }
    return (size);
}

char *my_strcat_delimiter(char *s1, char *s2, char *c)
{
    char *tmp = 0;
    char *new = 0;

    tmp = my_strcat(s1, c);
    if (tmp == 0)
        return (0);
    new = my_strcat(tmp, s2);
    free(tmp);
    return (new);
}

char **env_to_array(t_env *env)
{
    char **new = 0;
    t_env *tmp = env;
    int i = 0;

    new = malloc(sizeof(char *) * (env_size(env) + 1));
    if (new <= 0)
        return (0);

    while (tmp) {
        new[i] = my_strcat_delimiter(tmp->key, tmp->data, ":");
        tmp = tmp->next;
        i++;
    }
    new[i] = 0;
    return (new);
}

int exec_line(t_shell *shell, char *input)
{
    char **command = 0;
    char *bin = 0;
    char **args = 0;

    command = mystr_cut(input, ' ');
    bin = command[0];
    if (command != 0 && command[0] != 0 && command[1] != 0) {
        args = &command[1];
    }
    if (is_internal(bin)) {
        return run_internal(bin, args, shell);
    } else {
        return run_system(shell, bin, command);
    }
    free(command);
}
