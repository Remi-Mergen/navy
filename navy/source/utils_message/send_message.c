/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** send_message
*/

#include "navy.h"

int my_pow(int nb, int power)
{
    int result = 1;
    for (int i = 0; i < power; ++i)
        result *= nb;
    return result;
}

static void send_message(int pid, int message)
{
    if (message == 0)
        return;
    if (message % 10 == 0) {
        send_message(pid, message / 10);
        usleep(WAIT);
        kill(pid, SIGUSR2);
    } else if (message % 10 == 1) {
        send_message(pid, message / 10);
        usleep(WAIT);
        kill(pid, SIGUSR1);
    }
}

void process_message(int remote_pid, int pos_x, int pos_y)
{
    int send = 0;
    int send2 = 0;

    pos_x -= 64;
    pos_y -= 48;
    for (int i = 7; pos_x != 0; i--, --pos_x) {
        send = pos_x > 0 ? send + my_pow(10, i) : send * 10;
    }
    for (int i = 7; pos_y != 0; send2 += my_pow(10, i), i--, --pos_y);
    send_message(remote_pid, send);
    send_message(remote_pid, send2);
}
