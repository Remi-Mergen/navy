/*
** EPITECH PROJECT, 2021
** navy
** File description:
** get_attack
*/

#include "navy.h"

static void handler(int signum, siginfo_t *info, void *context)
{
    my_strcat(settings.coo, signum == SIGUSR1 ? "1" : "0");
    (void)info;
    (void)context;
}

static void receive_attack(void)
{
    struct sigaction sa;
    int i = 0;

    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    if (sigemptyset(&sa.sa_mask) != 0)
        return;
    printf("\nwaiting for enemy's attack...\n");
    for (; i < 16; ++i) {
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        pause();
    }
    return;
}

static char **init_pos(void)
{
    char **pos = malloc(sizeof(char *) * 3);
    int i = 0;

    pos[0] = malloc(sizeof(char) * 9);
    pos[1] = malloc(sizeof(char) * 9);
    pos[2] = NULL;
    for (; i < 8; ++i)
        pos[0][i] = '0';
    for (i = 0; i < 8; ++i)
        pos[1][i] = '0';
    pos[0][8] = '\0';
    pos[1][8] = '\0';
    pos[0] = my_strncpy(pos[0], settings.coo, 7);
    pos[1] = my_strcpy(pos[1], &settings.coo[8]);
    pos[0][8] = '\0';
    pos[0][7] = settings.coo[7];
    return pos;
}

static int is_touched(maps_t *map)
{
    char **pos = decipher_message(init_pos());
    int pos_x = pos[0][0];
    int pos_y = pos[1][0];
    int touched = update_player_map(pos_y - 1, pos_x - 1, map);

    printf("%c%c: ", pos_x + 64, pos_y + 48);
    return touched;
}

int get_attack(maps_t *map)
{
    receive_attack();
    int var = is_touched(map);
    usleep(10000);
    if (var == 1) {
        kill(settings.remote_pid, SIGUSR1);
        --map->nb_boat;
        printf("hit\n");
    } else {
        kill(settings.remote_pid, SIGUSR2);
        printf("missed\n");
    }
    return 0;
}
