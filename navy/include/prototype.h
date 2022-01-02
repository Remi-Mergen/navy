/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** prototype
*/

#include "struct.h"

#ifndef PROTOTYPE_H_
    #define PROTOTYPE_H_
    int my_put_nbr(int nb);
    void my_putchar(char c);
    char *init_str(int size);
    int my_getnbr(char const *str);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    char *my_strcat(char *dest, char *src);
    char **init_array_str(int nb_line, int nb_col);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char *src, int n);
    void print_pid(int pid);
    int player_one(char *filepath);
    int player_two();
    int which_player(int ac, char **av);
    int player_win(maps_t *map);
    void attack_player(maps_t *map);
    char *get_input(void);
    int get_attack(maps_t *map);
    void process_message(int remote_pid, int pos_x, int pos_y);
    char **decipher_message(char **pos);
    char *input_file(char *filepath);
    void free_maps(maps_t maps);
    void display_maps(maps_t *maps);
    maps_t *create_maps(char *buffer);
    int update_player_map(int line, int letter, maps_t *maps);
    void update_enemy_map(int line, int letter, maps_t *maps, int hit);
#endif /* !PROTOTYPE_H_ */
