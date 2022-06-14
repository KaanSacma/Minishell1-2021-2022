/*
** EPITECH PROJECT, 2021
** B-PSU-101-BRU-1-1-minishell1-kaan.sacma
** File description:
** commandexecutor2.c
*/

#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "prototypes.h"

int execvecommand(char *path, char **args, char **env)
{
    int frk = 0;
    int status = 0;

    frk = fork();
    if (frk > 0)
        waitpid(frk, &status, WUNTRACED | WCONTINUED);
    else if (frk == 0)
        execve(path, args, env);
    return status;
}
