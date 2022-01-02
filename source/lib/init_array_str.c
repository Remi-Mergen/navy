/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** init_array_str.c
*/

#include <stdlib.h>

char **init_array_str(int nb_line, int nb_col)
{
    char **output = malloc(sizeof(char *) * nb_line);
    for (int i = 0; i < nb_line; i++) {
        output[i] = malloc(sizeof(char) * nb_col);
        for (int j = 0; j < nb_col; j++)
            output[i][j] = 0;
    }
    return output;
}
