/*
** EPITECH PROJECT, 2021
** MY_PUTSTR
** File description:
** Displays, one-by-one, the characters of a string.
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    while (*str)
        write(1, str++, 1);
    return (0);
}
