/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** display_maps.c
*/

#include "navy.h"

void display_maps(maps_t *maps)
{
    printf("my positions:\n |A B C D E F G H\n");
    printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%d", i + 1);
        printf("|");
        printf(maps->player[i]);
    }
}

void display_maps_enemy(maps_t *maps)
{
    printf("\nenemy's positions:\n |A B C D E F G H\n");
    printf("-+---------------\n");
    for (int i = 0; i < 8; i++)
        printf("%d|%s", i + 1, maps->enemy[i]);
}
