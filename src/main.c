/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** main
*/

#include "my.h"

int try_run(char *fullpath, char **params, t_shell *shell)
{
    int child = 0;
    int stat;

    if ((child = fork()) == 0) {
        exit(execve(fullpath, params, env_to_array(shell->env)));
        return (-1);
    }
    if (child > 0) {
        waitpid(child, &stat, 0);
        if (WIFSIGNALED(stat) == 1 && WTERMSIG(stat) == 11)
            my_putstr("Segmentation fault\n");
        if (WEXITSTATUS(stat) != 255) {
            return (0);
        }
    }
    return (1);
}

int run_system(t_shell *shell, char *bin, char **params)
{
    t_env *path = env_findkey(shell->env, "PATH");
    char **paths = 0;
    char *fullpath = 0;
    int i = 0;

    if (path != 0) {
        paths = my_str_to_word_array(path->data, ':');
        while (paths != 0 && paths[i] != 0) {
            fullpath = my_strcat_delimiter(paths[i], bin, "/");
            if (fullpath == 0 || try_run(fullpath, params, shell) == 0)
                return (0);
            free(fullpath);
            i++;
        }
    }
    if (try_run(bin, params, shell) == 0)
        return (0);
    write(1, bin, my_strlen(bin));
    my_putstr(": Command not found.\n");
    return (0);
}

char *join(char **tab, char c)
{
    char *new;
    int length = 0;
    t_triplet triplet = new_triplet();

    while (tab != 0 && tab[triplet.i] != 0)
        length = length + my_strlen(tab[triplet.i++]) + 1;
    new = malloc(sizeof(char) * (length + 1));
    if (new == 0)
        return (0);
    triplet.i = 0;
    while (tab != 0 && tab[triplet.i] != 0) {
        triplet.j = 0;
        if (triplet.k != 0)
            new[triplet.k++] = ' ';
        while (tab[triplet.i][triplet.j] != 0)
            new[triplet.k++] = tab[triplet.i][triplet.j++];
        triplet.i++;
    }
    new[triplet.k] = 0;
    return (new);
}

int main(int argc, char **argv, char **env)
{
    t_shell shell;

    shell.env = get_env(env);
    loop_shell(&shell);
    free_shell(&shell);
    return (0);
}
