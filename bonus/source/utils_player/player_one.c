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

static void game_loop(maps_t *map)
{
    void (*color_array[8])(void);

    is_bold(color_array) == NULL ? minif("is_bold error\n"): 0;
    int *colors = choose_colors();
    minif("\n");
    while (1) {
        color_array[colors[0]]();
        display_maps(map);
        color_array[colors[1]]();
        display_maps_enemy(map);
        color_array[colors[2]]();
        attack_player(map);
        settings.coo[0] = '\0';
        get_attack(map);
        if(player_win(map) == 1)
            break;
        minif("\n");
    }
}

int player_one(char *filepath)
{
    char *buffer = input_file(filepath);
    if (!buffer)
        return 84;
    settings.self_pid = getpid();
    maps_t *map = create_maps(buffer);
    settings.coo = malloc(sizeof(char));
    if (!settings.coo) {
        write(1, "malloc failed\n", 14);
        return 84;
    }
    if (map->player == 0)
        return (84);
    init_connexion_player_one();
    game_loop(map);
    reset();
    return 0;
}
