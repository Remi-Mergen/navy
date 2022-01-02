/*
** EPITECH PROJECT, 2022
** navy
** File description:
** is_bold
*/

#include "navy.h"

static int check_input(char *buf)
{
    if (my_strlen(buf) != 2)
        return 1;
    if (buf[0] != 'Y' && buf[1] != 'N')
        return 1;
    return 0;
}

static char get_yes_or_no(void)
{
    char **buff = malloc(sizeof(char *)*2);
    size_t size = 1;

    buff[0] = malloc(sizeof(char) * 2);
    buff[1] = NULL;
    buff[0][1] = '\0';
    minif("Do you want to bold the output ?\nY or N : ");
    while (getline(buff, &size, stdin) == -1 || check_input(*buff) == 1)
        write(1, "wrong input\nDo you want to bold the output ?\nY or N : ", 54);
    return buff[0][0];
}

char *is_bold(void (**result)(void))
{
    char answer = get_yes_or_no();
    void (*color_array[8])(void) = {black, red, green, yellow, blue,
                                    purple, cyan, white};
    void (*blod_color_array[8])(void) = {black_b, red_b, green_b,
                                            yellow_b, blue_b, purple_b,
                                            cyan_b, white_b};

    if (answer == 'N') {
        for (int i = 0; i < 8; i++)
            result[i] = color_array[i];
        return "OK";
    }
    if (answer == 'Y') {
        for (int i = 0; i < 8; i++)
            result[i] = blod_color_array[i];
        return "OK";
    }
    minif("Error!\n");
    return NULL;
}
