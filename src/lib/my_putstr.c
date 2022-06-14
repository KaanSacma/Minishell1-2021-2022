/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Displays one by one all the char of the string.
*/

#include "prototypes.h"

int my_putstr(char const *str)
{
    int n_str = 0;

    for (n_str = 0; str[n_str] != '\0'; n_str += 1)
        my_putchar(str[n_str]);
    return (0);
}
