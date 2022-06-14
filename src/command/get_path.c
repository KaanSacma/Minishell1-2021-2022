/*
** EPITECH PROJECT, 2021
** Unix System Programming2
** File description:
** get_path.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "prototypes.h"

int find_step_path(char *str, char sep)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == sep)
            nb += 1;
    }
    return nb;
}

int get_len_path(char *token)
{
    int count = 0;

    for (int i = 0; token[i] != '\0'; i += 1)
        count += 1;
    return count;
}

char **give_path(char *token, char **tab, int j)
{
    int path_len = 0;

    path_len = get_len_path(token);
    tab[j] = malloc(sizeof(char) * (path_len + 1));
    tab[j] = token;
    return tab;
}

int pathfinding(char *str, const char *name)
{
    int len = 0;
    int n = 0;

    for (len = 0; name[len] != '\0'; len += 1);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (name[n] == str[i])
            n += 1;
        else if (name[n] != str[i])
            return 0;
        if (len == n)
            return 1;
    }
    return 0;
}

char **get_path(char **env, stocker_t *stock)
{
    char **tab = NULL;

    for (int i = 0; env[i] != NULL; i += 1)
        if (pathfinding(env[i], "PATH=") == 1) {
            stock->maxelem = stock->maxfill = 0;
            tab = str_to_str_array(env[i] + 5, ':', stock);
            break;
        }
    return tab;
}
