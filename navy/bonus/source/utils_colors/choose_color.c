/*
** EPITECH PROJECT, 2022
** navy
** File description:
** choose_color
*/

#include "navy.h"

static int check_input(char *buf)
{
    if (my_strlen(buf) != 4)
        return 1;
    if (buf[0] < '1' || buf[1] > '8')
        return 1;
    return 0;
}

static void show_colors(void)
{
    minif("Choose 3 colors for : your positions | enemy's positions | game instructions\n");
    minif("Exemple : '523' to have your map in blue, the enemy position in red and the game instructions in green.\n");
    black_b();
    printf("1\t");
    red_b();
    printf("2\t");
    green_b();
    printf("3\t");
    yellow_b();
    printf("4\t");
    blue_b();
    printf("5\t");
    purple_b();
    printf("6\t");
    cyan_b();
    printf("7\t");
    white_b();
    printf("8\n");
}

int *choose_colors(void)
{
    int *colors = malloc(sizeof(int) * 3);
    char **buff = malloc(sizeof(char *) * 4);
    size_t size = 1;

    buff[0] = malloc(sizeof(char) * 2);
    buff[1] = NULL;
    buff[0][4] = '\0';
    show_colors();
    while (getline(buff, &size, stdin) == -1 || check_input(*buff) == 1)
        write(1, "wrong input\n", 12);
    for(int i = 0; i < 3; i++)
        colors[i] = buff[0][i] - 49;
    return colors;
}
