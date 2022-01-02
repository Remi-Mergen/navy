/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** main
*/

#include "navy.h"

extern settings_t settings = {0};

void display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    first_player_pid: only for the 2nd player,");
    my_putstr(" pid of the first player.\n");
    my_putstr("    navy_positions: file representing the positions");
    my_putstr(" of the ships.\n");
}

int main(int ac, char **av)
{
    settings.self_pid = 0;
    settings.remote_pid = 0;
    if (ac < 2 || ac > 3)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        display_usage();
        return 0;
    }
    which_player(ac, av);
    return 0;
}
