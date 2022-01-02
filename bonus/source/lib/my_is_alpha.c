/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** my_is_alpha
*/

int is_alpha(char *str)
{
    for (int i = 0; str[i]; str += 1) {
        if (!(str[i] < 33 || str[i] > 126))
            return (1);
    }
    return 0;
}
