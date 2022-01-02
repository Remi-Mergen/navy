/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-navy-remi.mergen
** File description:
** input_file
*/

#include "../include/navy.h"

int check_line(char *line)
{
    for (int i = 1; line[i] != '\n'; i++) {
        if (i > 6)
            return 84;
        if (i % 3 == 1 && line[i] != ':')
            return 84;
        if (i % 3 == 2 && (line[i] < 'A' || line[i] > 'H'))
            return 84;
        if (i % 3 == 0 && (line[i] < '1' || line[i] > '8'))
            return 84;
    }
    return 0;
}

int check_if_file_correct(char *buffer)
{
    for (int i = 0; i < 32 || buffer[i] != '\0'; i += 8) {
        if (buffer[i] < '2' || buffer[i] > '5')
            return 84;
        if (check_line(&buffer[i]) == 84)
            return 84;
    }
    return 0;
}

char *read_file(char *filepath, int fd)
{
    int rd = 0;
    char *buffer = init_str(34);

    rd = read(fd, buffer, 32);
    if (rd < 0) {
        printf("RD NOT OK\n");
        return ("E");
    } if (rd != 32) {
        write(1, "Incorrect file\n", 15);
        return ("E");
    } else
        buffer[33] = '\0';
    if (check_if_file_correct(buffer) == 84) {
        my_putstr("Incorrect file\n");
        return "E";
    }
    return (buffer);
}

char *open_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd < 0) {
        printf("OPEN NOT OK\n");
        return "E";
    }
    return (read_file(filepath, fd));
}

static char *get_the_input(char *filepath)
{
    size_t size = 8;
    char *buffer = malloc(sizeof(char) * size);
    ssize_t line_size = 0;

    printf("Reading %s\n", filepath);
    line_size = getline(&buffer, &size, filepath);
    if (line_size < 32 || line_size > 33) {
        write(2, "Incorrect input\n", 16);
        return "E";
    }
    printf("READLINE      [OK]");
    return (buffer);
}
/*
char *input_file(char *filepath)
{
    printf("HEY\n");
    char *ships = open_file(filepath);
    if (ships == "E")
        return ("E");
    printf("SHIPS         [OK]\n");
    return (ships);
}
 */
