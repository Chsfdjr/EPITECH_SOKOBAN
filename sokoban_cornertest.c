/*
** EPITECH PROJECT, 2022
** corner test
** File description:
** c
*/

#include "include/sokoban.h"

int tlc (soko game, int test, int i)
{
    if ((game.map[game.box[i].y + 1][game.box[i].x] == '#') &&
        (game.map[game.box[i].y][game.box[i].x - 1] == '#'))
        test = 1;
    return test;
}

int trc (soko game, int test, int i)
{
    if ((game.map[game.box[i].y - 1][game.box[i].x] == '#') &&
        (game.map[game.box[i].y][game.box[i].x - 1] == '#'))
        test = 1;
    return test;
}

int blc (soko game, int test, int i)
{
    if ((game.map[game.box[i].y - 1][game.box[i].x] == '#') &&
        (game.map[game.box[i].y][game.box[i].x - 1] == '#'))
        test = 1;
    return test;
}

int brc (soko game, int test, int i)
{
    if ((game.map[game.box[i].y - 1][game.box[i].x] == '#') &&
        (game.map[game.box[i].y][game.box[i].x - 1] == '#'))
        test = 1;
    return test;
}
