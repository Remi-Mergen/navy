/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** Counts and returns the number of characters
** found in the string passed as parameter.
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
