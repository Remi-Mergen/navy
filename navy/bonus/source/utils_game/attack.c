/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** attack
*/

#include "navy.h"

static void handler(int signum, siginfo_t *info, void *context)
{
    if (signum == SIGUSR1) {
        printf("hit\n");
        settings.var = 1;
    } else {
        printf("missed\n");
        settings.var = 2;
    }
    (void)info;
    (void)context;
}

static int is_enemy_touched(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    if (sigemptyset(&sa.sa_mask) != 0)
        return 84;
    sigaction(SIGUSR1, &sa, ((void *)0));
    sigaction(SIGUSR2, &sa, ((void *)0));
    pause();
    return 0;
}

void attack_player(maps_t *map)
{
    settings.var = 0;
    char *input = get_input();
    printf("%c%c: ", input[0], input[1]);
    process_message(settings.remote_pid,
                    input[0], input[1]);
    is_enemy_touched();
    if (settings.var == 1) {
        --map->nb_boat_enemy;
        update_enemy_map(input[1] - 49, input[0] - 65, map, 1);
    } else
        update_enemy_map(input[1] - 49, input[0] - 65, map, 0);
    return;
}
