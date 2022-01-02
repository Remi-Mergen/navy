/*
** EPITECH PROJECT, 2021
** navy
** File description:
** decipher_message
*/

#include "navy.h"

char **decipher_message(char **pos)
{
    int a = 0;
    int b = 0;

    for (int i = 0; i < 8; ++i) {
        a += pos[0][i] - 48;
    }
    for (int i = 0; i < 8; ++i)
        b += pos[1][i] - 48;
    pos[0][0] = a;
    pos[0][1] = '\0';
    pos[1][0] = b;
    pos[1][1] = '\0';
    return pos;
}
