/*
** EPITECH PROJECT, 2021
** B-PSU-101-BRU-1-1-minishell1-kaan.sacma
** File description:
** my_env2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

char **copy_paste_env(int *i, int *j, char **env)
{
    int len_lane = 0;
    int len = find_null(env);
    char **env2 = malloc(sizeof(char *) * (len + 2));

    for (*i = 0; env[*i] != NULL; *i += 1) {
        len_lane = find_len_lane(env[*i]);
        env2[*i] = malloc(sizeof(char) * (len_lane + 1));
        for (*j = 0; env[*i][*j] != '\0'; *j += 1)
            env2[*i][*j] = env[*i][*j];
        env2[*i][*j] = '\0';
    }
    return env2;
}

char **copy_paste_name(char **env2, char *name, int *i)
{
    int len_lane = find_len_lane(name);
    int k = 0;

    env2[*i] = malloc(sizeof(char) * (len_lane + 2));
    for (k = 0; name[k] != '\0'; k += 1)
        env2[*i][k] = name[k];
    env2[*i][k] = '=';
    env2[*i][k + 1] = '\0';
    env2[*i + 1] = NULL;
    return env2;
}

char **copy_paste_name_args(char **env2, char *name, char *args, int *i)
{
    int len_lane = find_len_lane(name);
    int len_lane2 = find_len_lane(args);
    int k = 0;
    int l = 0;

    env2[*i] = malloc(sizeof(char) * ((len_lane + len_lane2) + 2));
    for (k = 0; name[k] != '\0'; k += 1)
        env2[*i][k] = name[k];
    env2[*i][k] = '=';
    k += 1;
    for (l = 0; args[l] != '\0'; l += 1, k += 1)
        env2[*i][k] = args[l];
    env2[*i][k] = '\0';
    env2[*i + 1] = NULL;
    return env2;
}

char **copy_env2(char **env, char *name, char *args)
{
    int j = 0;
    int i = 0;
    char **env2 = NULL;

    env2 = copy_paste_env(&i, &j, env);
    env2 = copy_paste_name(env2, name, &i);
    env2 = copy_paste_name_args(env2, name, args, &i);
    return env2;
}

void replace_by_name(stocker_t *stock, int index, char *name)
{
    int len_lane = find_len_lane(name);
    int i = 0;

    free(stock->env[index]);
    stock->env[index] = malloc(sizeof(char) * (len_lane + 2));
    for (i = 0; name[i] != '\0'; i += 1)
        stock->env[index][i] = name[i];
    stock->env[index][i] = '=';
    stock->env[index][i + 1] = '\0';
}
