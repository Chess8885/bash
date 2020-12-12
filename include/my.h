/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

struct s_triplet {
    int i;
    int j;
    int k;
};

typedef struct s_triplet t_triplet;

struct s_env
{
    char *key;
    char *data;
    struct s_env *next;
};

typedef struct s_env t_env;

struct  s_shell
{
    char **path;
    t_env *env;
    char *raw_input;
    char *command;
    char **arguments;
};

typedef struct s_shell t_shell;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strstr(char *s1, char *s2);
char **my_str_to_word_array(char *str, char c);
char **darray_empty();
void darray_free(char **src);
char **darray_copy(char **src);
int darray_length(char **src);
t_env *get_env(char **env);
void print_env(t_env *env);
void free_shell(t_shell *shell);
char *mystr_copy(char *src, char stop_char);
char *mystr_trim(char *src, char limiter);
char **mystr_cut(char *src, char limiter);
t_env *new_env(char *entry);
void my_setenv(t_shell *shell, char *key, char *data);
void my_unsetenv(t_shell *shell, char *key);
int is_internal(char *bin);
int run_internal(char *bin, char **args, t_shell *shell);
int run_system(t_shell *shell, char *bin, char **params);
t_env *env_findkey(t_env *env, char *key);
int exec_line(t_shell *shell, char *input);
char **env_to_array(t_env *env);
void loop_shell(t_shell *shell);
struct s_triplet new_triplet(void);
char *trim(char *str);
char *replace_str(char *str, char c, char c2);
char *join(char **tab, char c);
char *replace_str(char *str, char c, char c2);
char *trim(char *str);
char *mystr_copy(char *src, char stop_char);
char *copy_trim(char *str);
void free_shell(t_shell *shell);
void darray_free(char **src);
char **darray_copy(char **src);
char *str_copy(char *src);
int darray_length(char **src);
char **darray_empty(void);
char *my_strcat_delimiter(char *s1, char *s2, char *c);
