/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** display_maps.c
*/

#include "navy.h"

void display_maps(maps_t *maps)
{
    my_putstr("my positions:\n |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_put_nbr(i + 1);
        my_putstr("|");
        my_putstr(maps->player[i]);
    }
    my_putstr("\nenemy's positions:\n |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i < 8; i++)
        minif("%d|%s", i + 1, maps->enemy[i]);
}
