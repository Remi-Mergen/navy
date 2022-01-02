/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** player_one
*/

#include "navy.h"

static void connexion_player_one(int signum, siginfo_t *info, void *context)
{
    write(1, "\nenemy connected\n\n", 18);
    settings.remote_pid = info->si_pid;
    usleep(10000);
    if (kill(info->si_pid, SIGUSR1) == -1)
        write(1, "Error pid\n", 10);
    (void)signum;
    (void)context;
}

static void init_connexion_player_one(void)
{
    struct sigaction act = {0};

    act.sa_sigaction = connexion_player_one;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    print_pid(settings.self_pid);
    my_putstr("waiting for enemy connection...\n");
    sigaction(SIGUSR2, &act, NULL);
    pause();
}

static int check_errors(maps_t *map, settings_t settings)
{
    if (map->player == 0)
        return 84;
    if (!settings.coo)
        return 84;
    return 1;
}

int player_one(char *filepath)
{
    char *buffer = input_file(filepath);
    if (!buffer)
        return 84;
    settings.self_pid = getpid();
    maps_t *map = create_maps(buffer);
    settings.coo = malloc(sizeof(char));
    if (check_errors(map, settings) == 84)
        return 84;
    init_connexion_player_one();
    while (1) {
        display_maps(map);
        attack_player(map);
        settings.coo[0] = '\0';
        get_attack(map);
        if(player_win(map) == 1)
            break;
        minif("\n");
    }
    return 0;
}
