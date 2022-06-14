/*
** EPITECH PROJECT, 2021
** B-PSU-101-BRU-1-1-minishell1-kaan.sacma
** File description:
** my_cd2.c
*/

#include <unistd.h>
#include "prototypes.h"

int args_cmpt(char **args)
{
    int cmpt = 0;

    for (cmpt = 0; args[cmpt] != NULL; cmpt += 1);
    return cmpt;
}

int my_back(char **oldpwd, char **oldpwd2)
{
    int checker = 0;

    *oldpwd2 = getcwd(*oldpwd2, 1000);
    checker = chdir(*oldpwd);
    *oldpwd = my_strcy(*oldpwd2);
    return checker;
}

int my_move(char **oldpwd, char **args)
{
    int checker = 0;

    *oldpwd = getcwd(*oldpwd, 1000);
    checker = chdir(args[1]);
    checker = access_denied(args[1], checker);
    return checker;
}
