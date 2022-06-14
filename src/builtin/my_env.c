/*
** EPITECH PROJECT, 2021
** B-PSU-101-BRU-1-1-minishell1-kaan.sacma
** File description:
** my_env.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "prototypes.h"

int find_null(char **env)
{
    int len = 0;

    for (len = 0; env[len] != NULL; len += 1);
    return len;
}

int find_len_lane(char *str)
{
    int len = 0;

    for (len = 0; str[len] != '\0'; len += 1);
    return len;
}

void free_tab(char **env)
{
    for (int i = 0; env[i] != NULL; i += 1)
        free(env[i]);
    free(env);
}

char **copy_env(char **env, char *name)
{
    int j = 0;
    int i = 0;
    char **env2 = NULL;

    env2 = copy_paste_env(&i, &j, env);
    env2 = copy_paste_name(env2, name, &i);
    free_tab(env);
    return env2;
}

void my_setenv(stocker_t *stock, char **args)
{
    if (args_cmpt(args) == 1) {
        show_env(stock->env);
        return;
    } if (args_cmpt(args) == 2 && alphanum_detect(args[1]) == 0) {
        if (place_name_to_env(stock, args) == 1)
            return;
        stock->env = copy_env(stock->env, args[1]);
    } else if (args_cmpt(args) == 3 && alphanum_detect(args[1]) == 0) {
        if (place_name_args_to_env(stock, args) == 1)
            return;
        stock->env = copy_env2(stock->env, args[1], args[2]);
    } else {
        too_many_args(args);
    }
}
