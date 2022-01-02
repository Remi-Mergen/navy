/*
** EPITECH PROJECT, 2022
** navy
** File description:
** color_two
*/

#include <stdio.h>

void purple(void)
{
    printf("\033[0;35m");
}

void cyan(void)
{
    printf("\033[0;36m");
}

void white(void)
{
    printf("\033[0;37m");
}

void reset(void)
{
    printf("\033[0m");
}
