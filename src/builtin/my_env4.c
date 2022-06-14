/*
** EPITECH PROJECT, 2021
** B-PSU-101-BRU-1-1-minishell1-kaan.sacma
** File description:
** my_env4.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "prototypes.h"
#include "struct.h"

void too_many_args(char **args)
{
    if (args_cmpt(args) > 3)
        write(2, "setenv: Too many arguments.\n", 29);
}

int place_name_args_to_env(stocker_t *stock, char **args)
{
    for (int i = 0; stock->env[i] != NULL; i += 1)
        if (pathfinding(stock->env[i], args[1]) == 1) {
            replace_by_name_args(stock, i, args[1], args[2]);
            return 1;
        }
    return 0;
}
