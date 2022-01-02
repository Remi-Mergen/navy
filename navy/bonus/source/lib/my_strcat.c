/*
** EPITECH PROJECT, 2021
** MY_STRCAT
** File description:
** Concatenates two strings.
*/

#include "navy.h"

char *my_strcat(char *dest, char *src)
{
    int dest_len = my_strlen(dest);
    char *new_dest = malloc(sizeof(char) * (dest_len + my_strlen(src)));
    int i = 0;

    my_strcpy(new_dest, dest);
    for (; src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return (new_dest);
}
