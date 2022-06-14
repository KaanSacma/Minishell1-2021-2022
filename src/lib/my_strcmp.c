/*
** EPITECH PROJECT, 2021
** Unix System Programming2
** File description:
** my_strcmp.c
*/

int my_strcmp(char const *str1, char const *str2)
{
    int len_str1 = 0;
    int len_str2 = 0;

    for (len_str1 = 0; str1[len_str1] != '\0'; len_str1 += 1);
    for (len_str2 = 0; str2[len_str2] != '\0'; len_str2 += 1);
    if (len_str1 > len_str2 || len_str1 < len_str2)
        return 1;
    for (int i = 0; str1[i] != '\0'; i += 1)
        if (str1[i] != str2[i])
            return 1;
    return 0;
}
