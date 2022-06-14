/*
** EPITECH PROJECT, 2021
** Unix System Programming2
** File description:
** main.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "prototypes.h"
#include "struct.h"

void show_env(char **env)
{
    for (int i = 0; env[i] != NULL; i += 1) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
}

void env_to_struct(stocker_t *stock, char **env)
{
    int len_lane = 0;
    int j = 0;
    int i = 0;
    int len = find_null(env);

    stock->env = malloc(sizeof(char *) * (len + 1));
    for (i = 0; env[i] != NULL; i += 1) {
        len_lane = find_len_lane(env[i]);
        stock->env[i] = malloc(sizeof(char) * (len_lane + 1));
        for (j = 0; env[i][j] != '\0'; j += 1)
            stock->env[i][j] = env[i][j];
        stock->env[i][j] = '\0';
    }
    stock->env[i] = NULL;
}

void loop_in_execution(stocker_t *stock)
{
    size_t n = 0;
    ssize_t nread = 0;
    char *program = NULL;
    char **list_env = get_path(stock->env, stock);
    char **execution = NULL;

    stock->exit = 0;
    while (stock->exit == 0) {
        show_type();
        nread = getline(&program, &n, stdin);
        if (nread != -1) {
            list_env = get_path(stock->env, stock);
            execution = array_command(stock, program, nread);
            commandexecution(execution, list_env, stock);
            free_tab(execution);
            free_tab(list_env);
        } else
            ctrl_d(stock);
    }
}

void env_null(stocker_t *stock)
{
    free_tab(stock->env);
    stock->env = malloc(sizeof(char *) * 2);
    stock->env[0] = copy_str("PATH=/bin\0");
    stock->env[1] = NULL;
}

int main(int ac, char **av, char **env)
{
    int exit = 0;
    stocker_t *stock = malloc(sizeof(stocker_t));

    stock->errcheck = 0;
    if ((ac < 1 || ac > 1) && my_strcmp(av[0], "./mysh") == 1)
        return 84;
    env_to_struct(stock, env);
    if (stock->env[0] == NULL)
        env_null(stock);
    loop_in_execution(stock);
    free_tab(stock->env);
    exit = stock->errcheck;
    free(stock);
    return exit;
}
