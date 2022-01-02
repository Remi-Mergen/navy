/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct {
        int nb_boat;
        int nb_boat_enemy;
        char **player;
        char **enemy;
    } maps_t;

    typedef struct {
        pid_t self_pid;
        pid_t remote_pid;
        char *coo;
        int var;
    } settings_t;

#endif /* !STRUCT_H_ */
