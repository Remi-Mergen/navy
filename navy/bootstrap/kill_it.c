/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** kill_it
*/

#include<stdio.h>
#include<wait.h>
#include<signal.h>
#include <stdlib.h>

int main(int ac, char **av) {
    kill(atoi(av[1]), SIGUSR1);
    return (0);
}
