/*
** EPITECH PROJECT, 2021
** B-PSU-101-BRU-1-1-minishell1-kaan.sacma
** File description:
** error_execute.c
*/

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "prototypes.h"

int command_not_found(char *str)
{
    if (my_strcmp(check_program_exist(str), "unknow file") == 0) {
        write(2, str, my_strlen(str));
        write(2, ": Command not found.\n", 21);
        return 1;
    }
    return 0;
}

void show_error(int errnum)
{
    char *code_error = NULL;

    if (WTERMSIG(errnum)) {
        code_error = strsignal(WTERMSIG(errnum));
        write(2, code_error, my_strlen(code_error));
        if (WCOREDUMP(errnum))
            write(2, " (core dumped)", 15);
        write(2, "\n", 1);
    }
}

void not_a_directory(char *str)
{
    write(2, str, my_strlen(str));
    write(2, ": Not a directory.\n", 19);
}

int access_denied(char *str, int checker)
{
    if (access(str, X_OK) == -1 && checker != 0) {
        write(2, str, my_strlen(str));
        write(2, ": Permission denied.\n", 21);
        checker = 0;
        return checker;
    }
    return checker;
}

void detect_error(int error, char *name)
{
    if (error == 136) {
        write(2, "Floating exception\n", 19);
        return;
    }
    if (WIFSIGNALED(error))
        show_error(error);
    else
        access_denied(name, error);
}
