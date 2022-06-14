/*
** EPITECH PROJECT, 2021
** B-PSU-101-BRU-1-1-minishell1-kaan.sacma
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int len = 0;

    for (len = 0; str[len] != '\0'; len += 1);
    return len;
}
