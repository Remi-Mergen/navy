/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** which_player
*/

#include "navy.h"

int which_player(int ac, char **av)
{
    int error = 0;

    if (ac == 2) {
        error = player_one(av[1]);
        return (error);
    } else if (ac == 3)
        error = player_two(my_getnbr(av[1]), av[2]);
    return (error);
}
