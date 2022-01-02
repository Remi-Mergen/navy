/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** update_maps.c
*/

#include "navy.h"

int update_player_map(int line, int letter, maps_t *maps)
{
    if (maps->player[line][letter * 2] != '.') {
        maps->player[line][letter * 2] = 'x';
        return 1;
    } else {
        maps->player[line][letter * 2] = 'o';
        return 0;
    }
}

void update_enemy_map(int line, int letter, maps_t *maps, int hit)
{
    if (hit == 1)
        maps->enemy[line][letter * 2] = 'x';
    else
        maps->enemy[line][letter * 2] = 'o';
}
