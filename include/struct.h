/*
** EPITECH PROJECT, 2021
** Unix System Programming2
** File description:
** struct.h
*/

#ifndef __STRUCT__
    #define __STRUCT__

typedef struct stocker_s {
    int maxfill;
    int maxelem;
    int errcheck;
    int exit;
    char **env;
} stocker_t;

#endif