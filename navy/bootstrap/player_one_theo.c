/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** player_one_theo
*/

#include "../include/navy.h"
#include "../include/minif.h"

pid_t remote_pid = 0;

static void enemy_signal(int sig, siginfo_t *info, void *context)
{
    (void)sig;
    (void)context;
    minif("\nenemy connected\n");
    remote_pid = info->si_pid;
}

int init_server(void)
{
    struct sigaction act;
    settings_t *settings = malloc(sizeof(settings_t));

    act.sa_sigaction = enemy_signal;
    act.sa_flags = SA_SIGINFO;
    if (sigemptyset(&act.sa_mask) != 0)
        return (84);
    minif("my_pid: %d\nwaiting for enemy connection...\n", getpid());
    if (sigaction(SIGUSR1, &act, NULL) != 0)
        return (84);
    pause();
    if (remote_pid == 0)
        return (84);
    settings->self_pid = getpid();
    settings->remote_pid = remote_pid;
    return play_game(settings);
}
