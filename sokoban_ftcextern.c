/*
** EPITECH PROJECT, 2022
** soko
** File description:
** ftc
*/

#include "include/sokoban.h"

void display_map(char **map, int y)
{
    for (int i = 0 ; i < y ; i++)
        printw("%s\n", map[i]);
}

void free_struct(soko game)
{
    free(game.box);
    free(game.store);
    for (int i = 0 ; game.map[i] != NULL ; i++)
        free(game.map[i]);
}
