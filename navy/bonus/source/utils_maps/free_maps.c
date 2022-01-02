/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** free_maps.c
*/

#include "navy.h"

void free_maps(maps_t maps)
{
    for (int i = 0; i < 10; i++) {
        free(maps.player[i]);
        free(maps.enemy[i]);
    }
    free(maps.player);
    free(maps.enemy);
}
