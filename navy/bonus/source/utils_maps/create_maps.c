/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** create_maps.c
*/

#include "navy.h"

char **fill_blank_map(void)
{
    char **output = init_array_str(10, 18);
    for (int i = 0; i < 8; i++) {
        output[i][0] = '.';
        for (int j = 1; j < 16; j++) {
            output[i][j++] = ' ';
            output[i][j] = '.';
        }
        output[i][16] = '\n';
    }
    return output;
}

int check_coordinates(char *line, maps_t *maps)
{
    int y_it = line[2] - 'A';
    int y_end = line[5] - 'A';
    int x_it = line[3] - '0' - 1;
    int x_end = line[6] - '0' - 1   ;
    int diff_x = x_end - x_it;
    int diff_y = y_end - y_it;
    int not_dot = 0;

    for (int i = 0; i < diff_x + 1; i++) {
        for (int j = 0; j < (diff_y + 1) * 2; j += 2) {
            not_dot += (maps->player[i + x_it][j + y_it * 2] == '.') ? 0 : 1;
            j += (diff_y == 0) ? 1 : 0;
        }
    }
    if (not_dot != 0)
        return 84;
    else
        return 1;
}

int place_boat(char *line, maps_t *maps)
{
    int y_init = line[2] - 'A';
    int y_end = line[5] - 'A';
    int x_init = line[3] - '0' - 1;
    int x_end = line[6] - '0' - 1   ;
    int diff_x = x_end - x_init;
    int diff_y = y_end - y_init;
    int size = 0;

    if (diff_x + 1 != line[0] - '0' && diff_y + 1 != line[0] - '0')
        return 84;
    if (check_coordinates(line, maps) == 84)
        return 84;
    size = (diff_x < diff_y) ? diff_y : diff_x;
    for (int i = 0; i < diff_x + 1; i++) {
        for (int j = 0; j < (diff_y + 1) * 2; j += 2) {
            maps->player[i + x_init][j + y_init * 2] = size +  1 + '0';
            j += (diff_y == 0) ? 1 : 0;
        }
    }
    return 1;
}

void fill_map(char *buffer, maps_t *maps)
{
    for (int i = 0; i < 32; i += 8) {
        if (place_boat(&buffer[i], maps) == 84) {
            my_putstr("Incorrect file\n");
            maps->player = 0;
            return;
        }
    }
}

maps_t *create_maps(char *buffer)
{
    maps_t *maps = malloc(sizeof(maps_t));

    maps->nb_boat = 14;
    maps->nb_boat_enemy = 14;
    maps->player = fill_blank_map();
    maps->enemy = fill_blank_map();
    fill_map(buffer, maps);
    free(buffer);
    return maps;
}
