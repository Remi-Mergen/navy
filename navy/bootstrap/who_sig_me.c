/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** who_sig_me
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void handler(int signum, siginfo_t *info, void *context)
{
    struct sigaction oldact;

    printf("Le pid de l'émetteur est %d", info->si_pid);
    if (signum == SIGUSR1)
        printf(" et le signal SIGUSR1 est reçu !\n");
    if (signum == SIGUSR2)
        printf(" et le signal SIGUSR2 est reçu !\n");
}


int main(int ac, char **av)
{
    struct sigaction act = { 0 };
    int pid = getpid();

    printf("[%d]\n", pid);
    act.sa_sigaction = handler;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(atoi(av[1]), &act, NULL);
    sigaction(atoi(av[2]), &act, NULL);
    while (1);
}
