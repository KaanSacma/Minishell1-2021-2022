/*
** EPITECH PROJECT, 2021
** B-PSU-101-BRU-1-1-minishell1-kaan.sacma
** File description:
** more_fct_main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "prototypes.h"

void show_type(void)
{
    char dir[500];

    my_putstr("<");
    my_putstr(getcwd(dir, 500));
    my_putstr("> ");
}

char **array_command(stocker_t *stock, char *program, ssize_t nread)
{
    char **execution = NULL;

    program[nread - 1] = '\0';
    stock->maxelem = stock->maxfill = 0;
    execution = str_to_str_array(program, ' ', stock);
    return execution;
}

void ctrl_d(stocker_t *stock)
{
    my_putchar('\n');
    stock->exit = 84;
}