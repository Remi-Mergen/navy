/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** print_pid
*/

#include "navy.h"

void print_pid(int pid)
{
    write(1, "my_pid: ", 9);
    my_put_nbr(pid);
    write(1, "\n", 1);
    return;
}
