/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** qdfc
*/

#include "include/sokoban.h"

void it_is_map(int fd, int size)
{
    char *buffer = malloc(sizeof(char) * (size + 1));
    int rd = read(fd, buffer, size);
    char *nb = malloc(sizeof(char) * (size + 1));
    int largeur = count_largeur(buffer);
    int i = 0;
    int longer = 0;

    if (rd < 0)
        exit(84);
    buffer[rd] = '\0';
    for (i = 0 ; buffer[i] != '\0' ; i++) {
        if (buffer[i] != ' ' && buffer[i] != '#' && buffer[i] != '\n' &&
            buffer[i] != 'X' && buffer[i] != 'O' && buffer[i] != 'P')
            exit(84);
        else
            nb[i] = buffer[i];
    }
    nb[i] = '\0';
    longer = count_longer(buffer, longer);
    put_in_map(buffer, longer);
}

int count_longer(char *buffer, int longer)
{
    for (int i = 0 ; buffer[i] != '\0' ; i++) {
        if (buffer[i] == '\n')
            longer++;
    }
    return longer;
}

int count_largeur(char *buffer)
{
    int largeur = 0;

    for (int i = 0 ; buffer[i] != '\n' ; i++)
            largeur++;
    return largeur;
}

void *makepartofbuffer(char *map, char *buffer, int j)
{
    int i = 0;

    while (buffer[i] != '\n') {
        map[i] = buffer[i];
        j++;
        i++;
    }
    map[i] = '\0';
}
