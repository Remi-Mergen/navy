/*
** EPITECH PROJECT, 2021
** MY_PUT_NBR
** File description:
** Displays the number given as a parameter.
*/

#include <unistd.h>
#include "navy.h"

int my_put_nbr(int nb)
{
    if (nb == -2147483648)
        write(1, "-2147483648", 11);
    else {
        if (nb < 0) {
            my_putchar('-');
            nb = -nb;
        }
        if (nb >= 10) {
            my_put_nbr(nb / 10);
            my_put_nbr(nb % 10);
        } else
            my_putchar(nb + 48);
    }
    return (0);
}
