/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** signal_me
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int handler(int signum, siginfo_t *info, void *context)
{
    struct sigaction oldact;

    printf("Le pid de l'émetteur est %d", info->si_pid);
    if (signum == SIGUSR1)
        printf(" et le signal SIGUSR1 est reçu !\n");
        return (1);
    if (signum == SIGUSR2) {
        printf(" et le signal SIGUSR2 est reçu !\n");
        return (1);
    }
    return (0);
}


int main(int ac, char **av)
{
    struct sigaction act = { 0 };
    int pid = getpid();
    int *result = malloc(sizeof(int) * 2);

    printf("[%d]\n", pid);
    act.sa_sigaction = handler;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(10, &act, NULL);
    sigaction(12, &act, NULL);
    printf("[%d][%d]\n", result[0], result[1]);
    while (1);
}
