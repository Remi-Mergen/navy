/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** getnbr
*/

static int verif_int(long a)
{
    if (a < -2147483648 || a > 2147483647)
        return (0);
    else
        return ((int) a);
}

static int verif_len(char const *str)
{
    int count = 0;
    int i = 0;

    while (str[i] == '-' || str[i] == '+') {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        count++;
        i++;
    }
    if (count <= 10)
        return (1);
    return (0);
}

int my_getnbr(char const *str)
{
    int neg = 1;
    long res = 0;
    int i = 0;

    if (verif_len(str) == 0)
        return 0;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (res == 0)
            res += str[i] -'0';
        else
            res = (res * 10) + str[i] - '0';
        i++;
    }
    res *= neg;
    return (verif_int(res));
}
