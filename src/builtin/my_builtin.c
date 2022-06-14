/*
** EPITECH PROJECT, 2021
** Unix System Programming2
** File description:
** my_builtin.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "prototypes.h"

int my_builtin2(const char *program, char **args, stocker_t *stock)
{
    int result = 0;

    if (my_strcmp(program, "cd") == 0) {
        my_cd(stock->env, args);
        return 1;
    } else if (my_strcmp(program, "setenv") == 0) {
        my_setenv(stock, args);
        return 1;
    } else
        if (my_strcmp(program, "unsetenv") == 0) {
            my_unsetenv(stock, args);
            return 1;
        }
    return result;
}

int my_builtin(const char *program, char **args, stocker_t *stock)
{
    int exit = 0;
    int result = 0;

    if (my_strcmp(program, "exit") == 0) {
        if (args_cmpt(args) > 2) {
            write(2, "exit: Expression Syntax.\n", 26);
            return 1;
        } if (args[1] != NULL)
            exit = my_getnbr(args[1]);
        stock->errcheck = exit;
        stock->exit = 1;
        return 1;
    } else if (my_strcmp(program, "env") == 0) {
        show_env(stock->env);
        return 1;
    } else
        result = my_builtin2(program, args, stock);
    return result;
}
