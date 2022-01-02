/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** get_input
*/

#include "navy.h"

int check_input(char *buf)
{
    if (my_strlen(buf) != 3)
        return 1;
    if (buf[0] < 'A' || buf[0] > 'H')
        return 1;
    if (buf[1] < '1' || buf[1] > '8')
        return 1;
    return 0;
}

char *get_input(void)
{
    char **buff = malloc(sizeof(char *)*2);
    size_t size = 2;

    buff[0] = malloc(sizeof(char) * 3);
    buff[1] = NULL;
    buff[0][2] = '\0';
    printf("\nattack: ");
    while (getline(buff, &size, stdin) == -1 || check_input(*buff) == 1)
        printf("wrong position\nattack: ");
    return *buff;
}
