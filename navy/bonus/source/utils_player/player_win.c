/*
** EPITECH PROJECT, 2021
** navy
** File description:
** player_win
*/

#include "navy.h"

int player_win(maps_t *map)
{
    if (map->nb_boat < 1) {
        minif("Enemy won");
        return 1;
    } else if (map->nb_boat_enemy < 1) {
        minif("I won");
        return 1;
    } else
        return 0;
}
