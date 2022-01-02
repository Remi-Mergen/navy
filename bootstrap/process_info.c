/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** my_bootstrap
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("pid : %lu\n", pid);
    printf("ppid: %lu\n", ppid);
    printf("pgid: %lu\n", getpgid(pid));
    exit(EXIT_SUCCESS);
}
