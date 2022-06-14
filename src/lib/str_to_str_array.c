/*
** EPITECH PROJECT, 2021
** Unix System Programming2
** File description:
** str_to_str_array.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int find_step(char *str, char sep)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == sep || str[i] == '\t')
            nb += 1;
    }
    return nb;
}

int find_len_elem(char *str, char sep, stocker_t *stock)
{
    int count = 0;

    for (; str[stock->maxelem] != sep && str[stock->maxelem]
        != '\0'; stock->maxelem += 1) {
        count += 1;
    }
    stock->maxelem += 1;
    return count;
}

void fill_tab(char *str, char *dest, char sep, stocker_t *stock)
{
    int j = 0;

    for (j = 0; str[stock->maxfill] != sep
        && str[stock->maxfill] != '\0'
        && str[stock->maxfill] != '\t'; j += 1, stock->maxfill += 1)
        dest[j] = str[stock->maxfill];
    stock->maxfill += 1;
    dest[j] = '\0';
}

char **sort_array(char **array)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int len = 0;

    for (i = 0; array[i] != NULL; i += 1)
        if (array[i][0] == 0) {
            for (j = i; array[j][0] == 0; j += 1)
                if (array[j + 1] == NULL) {
                    array[i] = NULL; return array;
                }
            for (len = 0; array[j][len] != '\0' && array[j] != NULL; len += 1);
            array[i] = malloc(sizeof(char) * (len + 1));
            for (x = 0; array[j][x] != '\0'; x += 1)
                array[i][x] = array[j][x];
            free(array[j]); array[j] = malloc(sizeof(char));
            array[j][0] = array[i][x] = '\0';
            i = 0;
        }
    array[i] = NULL; return array;
}

char **str_to_str_array(char *str, char sep, stocker_t *stock)
{
    int i = 0;
    int len = 0;
    int nb = find_step(str, sep);
    char **tab = malloc(sizeof(char *) * (nb + 2));

    for (i = 0; i < (nb + 1); i += 1) {
        len = find_len_elem(str, sep, stock);
        tab[i] = malloc(sizeof(char) * (len + 1));
        fill_tab(str, tab[i], sep, stock);
    }
    tab[i] = NULL;
    tab = sort_array(tab);
    return tab;
}
