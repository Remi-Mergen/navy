/*
** EPITECH PROJECT, 2021
** MY_STRCPY
** File description:
** Copies a string into another.
*/

#include "navy.h"

char *my_strcpy(char *dest, char const *src)
{
    long len = my_strlen(src) + 1;
    for (int i = 0; i < len; i++)
        dest[i] = src[i];
    return (dest);
}
