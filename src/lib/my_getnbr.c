/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** Returns a number and sent to the function as a string.
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int j = 0;
    int number = 0;

    for (i = 0; (str[i] < '0' || str[i] > '9') && str[i] != '\0'; i += 1);
    for (j = i; ((str[j] >= '0' && str[j] <= '9') && str[j] != '\0'); j += 1);
    for (; i < j; i += 1) {
        number *= 10;
        number += (str[i] - '0');
    }
    i = i - j;
    if (str[i - 1] == '-')
            number *= -1;
    return number;
}
