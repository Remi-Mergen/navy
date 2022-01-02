/*
** EPITECH PROJECT, 2021
** MY_STRNCPY
** File description:
** Copies n characters from a string into another.
*/

char *my_strncpy(char *dest, char *src, int n)
{
    for (int i = 0; ((i < n) && (dest[i] != '\0')) ||
        ((i < n) && (src[i] != '\0')); i++)
            dest[i] = src[i];
    return (dest);
}
