/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** player_two
*/

#include "navy.h"

static void connexion_player_two(int signum, siginfo_t *info, void *context)
{
    write(1, "successfully connected\n\n", 24);
    (void)signum;
    settings.remote_pid = info->si_pid;
    (void)context;
}

static int init_connexion_player_two(int pid)
{
    struct sigaction act = {0};
    pid_t my_pid = getpid();

    if (kill(pid, SIGUSR2) == -1) {
        write(1, "Error pid\n", 10);
        return 84;
    }
    print_pid(my_pid);
    act.sa_sigaction = connexion_player_two;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);
    pause();
    return 0;
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
        settings.coo[0] = '\0';
        get_attack(map);
        attack_player(map);
        if(player_win(map) == 1)
            break;
        minif("\n");
    }
}

int player_two(int pid, char *filepath)
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
    if (init_connexion_player_two(pid) == 84)
        return 84;
    game_loop(map);
    reset();
    return 0;
}
