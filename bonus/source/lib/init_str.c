/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** init_str.c
*/

#include <stdlib.h>

char *init_str(int size)
{
    char *output = malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
        output[i] = 0;
    return output;
}
