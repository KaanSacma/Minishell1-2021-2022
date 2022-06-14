/*
** EPITECH PROJECT, 2021
** B-PSU-101-BRU-1-1-minishell1-kaan.sacma
** File description:
** my_cd.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

char *my_strcy(char *str)
{
    int len = 0;
    int i = 0;
    char *tmp = NULL;

    for (len = 0; str[len] != '\0'; len += 1);
    tmp = malloc(sizeof(char) * (len + 1));
    for (i = 0; str[i] != '\0'; i += 1)
        tmp[i] = str[i];
    tmp[i] = '\0';
    return tmp;
}

char *my_getpwd(char *pwd, char *name)
{
    char *string = malloc(sizeof(char) * 200);
    int tmp = 0;

    for (int i = 0; pwd[i] != '\0'; i += 1, tmp += 1)
        string[tmp] = pwd[i];
    string[tmp] = '/';
    tmp += 1;
    for (int x = 0; name[x] != '\0'; x += 1, tmp += 1)
        string[tmp] = name[x];
    string[tmp] = '\0';
    return string;
}

char *my_gethome(char **env)
{
    char *string = malloc(sizeof(char) * 200);
    int tmp = 0;

    for (int i = 0; env[i] != NULL; i += 1) {
        if (pathfinding(env[i], "HOME") == 1) {
            for (int j = 5; env[i][j] != '\0'; j += 1, tmp += 1)
                string[tmp] = env[i][j];
            string[tmp] = '\0';
            break;
        }
    }
    return string;
}

int my_home(char *home, char **env, char **oldpwd)
{
    int checker = 0;

    for (int i = 0; env[i] != NULL; i += 1) {
        if (pathfinding(env[i], "HOME=") == 1) {
            *oldpwd = getcwd(*oldpwd, 1000);
            home = my_gethome(env);
            checker = chdir(home);
            return checker;
        }
    }
    write(2, "cd: No home directory.\n", 23);
    return checker;
}

void my_cd(char **env, char **args)
{
    int checker = 0;
    char *home = NULL;
    static char *oldpwd = NULL;
    static char *oldpwd2 = NULL;

    if (args_cmpt(args) > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return;
    }
    if (args[1] == NULL || my_strcmp(args[1], "--") == 0)
        checker = my_home(home, env, &oldpwd);
    else if (args[1] != NULL) {
        if (my_strcmp(args[1], "-") == 0)
            checker = my_back(&oldpwd, &oldpwd2);
        else
            checker = my_move(&oldpwd, args);
    } if (checker < 0)
        not_a_directory(args[1]);
}
