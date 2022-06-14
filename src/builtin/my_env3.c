/*
** EPITECH PROJECT, 2021
** B-PSU-101-BRU-1-1-minishell1-kaan.sacma
** File description:
** my_env3.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "prototypes.h"

int place_name_to_env(stocker_t *stock, char **args)
{
    for (int i = 0; stock->env[i] != NULL; i += 1)
        if (pathfinding(stock->env[i], args[1]) == 1) {
            replace_by_name(stock, i, args[1]);
            return 1;
        }
    return 0;
}

int alphanum_detect(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((str[0] < 'A' || str[0] > 'Z') && (str[0] < 'a' || str[0] > 'z')) {
            my_putstr("setenv: Variable name must begin with a letter.\n");
            return 1;
        }
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')
            && (str[i] < '0' || str[i] > '9')) {
            my_putstr("setenv: Variable name must ");
            my_putstr("contain alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

void replace_by_name_args(stocker_t *stock, int index, char *name, char *args)
{
    int len_lane = find_len_lane(name);
    int len_lane2 = find_len_lane(args);
    int i = 0;
    int j = 0;

    free(stock->env[index]);
    stock->env[index] = malloc(sizeof(char) * ((len_lane + len_lane2) + 2));
    for (i = 0; name[i] != '\0'; i += 1)
        stock->env[index][i] = name[i];
    stock->env[index][i] = '=';
    i += 1;
    for (j = 0; args[j] != '\0'; j += 1, i += 1)
        stock->env[index][i] = args[j];
    stock->env[index][i] = '\0';
}

char *copy_str(char *name)
{
    int i = 0;
    int len = 0;
    char *str = NULL;

    for (len = 0; name[len] != '\0'; len += 1);
    str = malloc(sizeof(char) * (len + 1));
    for (i = 0; name[i] != '\0'; i += 1)
        str[i] = name[i];
    str[i] = '\0';
    return str;
}

void my_unsetenv(stocker_t *stock, char **args)
{
    char *tmp = NULL;
    int pos = 0;

    for (int i = 1; args[i] != NULL; i += 1) {
        for (pos = 0; pathfinding(stock->env[pos], args[i]) == 0
        && stock->env[pos + 1] != NULL; pos += 1);
        while (stock->env[pos] != NULL
            && pathfinding(stock->env[pos], args[i]) == 1) {
            if (stock->env[pos + 1] == NULL) {
                free(stock->env[pos]);
                stock->env[pos] = NULL;
                break;
            }
            tmp = copy_str(stock->env[pos]); free(stock->env[pos]);
            stock->env[pos] = copy_str(stock->env[pos + 1]);
            free(stock->env[pos + 1]);
            stock->env[pos + 1] = copy_str(tmp); free(tmp);
            pos += 1;
        }
    }
}
