/*
** EPITECH PROJECT, 2021
** Unix System Programming2
** File description:
** commandExecutor.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "prototypes.h"

int find_nb_args(char **program)
{
    int nb = 0;

    if (program[1] != NULL)
        for (int i = 1; program[i] != NULL; i += 1)
            nb += 1;
    return nb;
}

char *check_program_exist(char *program)
{
    struct stat sb;
    int exist = 0;

    if (stat(program, &sb) == -1)
        return "unknow file";
    exist = stat(program, &sb);
    if (exist == 0) {
        if (access(program, X_OK) != -1)
            return program;
    }
    return "unknow file";
}

char *check_program(char *name, char **env)
{
    int len = 0;
    int j = 0;
    char *program = NULL;

    for (int i = 0; env[i] != NULL; i += 1) {
        for (len = 0; env[i][len] != '\0'; len += 1);
        for (int x = 0; name[x] != '\0'; x += 1, len += 1);
        program = malloc(sizeof(char) * (len + 2));
        for (j = 0; env[i][j] != '\0'; j += 1)
            program[j] = env[i][j];
        program[j] = '/'; j += 1;
        for (int k = 0; name[k] != '\0'; k += 1, j += 1)
            program[j] = name[k];
        program[j] = '\0';
        if (my_strcmp(check_program_exist(program), "unknow file") != 0)
            return program;
        free(program);
    }
    return "unknow file";
}

char **create_args(char **program, char *path)
{
    int i = 1;
    int len = find_nb_args(program);
    char **args = malloc(sizeof(char *) * (len + 2));

    args[0] = path;
    for (i = 1; program[i] != NULL; i += 1)
        args[i] = program[i];
    args[i] = NULL;
    return args;
}

void commandexecution(char **program, char **list, stocker_t *stock)
{
    int status = 0;
    char *path = NULL;
    char **args = NULL;

    if (program[0] == NULL)
        return;
    path = check_program(program[0], list);
    args = create_args(program, path);
    if (my_builtin(program[0], args, stock) == 1)
        return;
    else if (my_strcmp(path, "unknow file") == 0) {
        if (command_not_found(program[0]) == 1)
            return;
        args = create_args(program, program[0]);
        status = execvecommand(program[0], args, stock->env);
        detect_error(status, program[0]);
    } else {
        status = execvecommand(path, args, stock->env);
        detect_error(status, path);
    }
}
