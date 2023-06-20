/*
** EPITECH PROJECT, 2022
** ftc of store
** File description:
** sokoban
*/

#include "include/sokoban.h"

soko all_test(soko game, int y)
{
    game = testing_box(game);
    testing_end(game, y);
    testing_loose(game, y);
    return game;
}

void testing_end(soko game, int y)
{
    int test = 0;

    for (int i = 0 ; i < game.nb_store ; i++) {
        if (game.map[game.store[i].y][game.store[i].x] == 'X')
            test++;
    }
    if (test == game.nb_store) {
        display_map(game.map, y);
        exit(0);
    }
}

void testing_loose(soko game, int y)
{
    int test = 0;

    for (int i = 0 ; i < game.nb_box ; i++) {
        if (test == -1)
            return;
        if (((game.map[game.box[i].y + 1][game.box[i].x] == '#') &&
            (game.map[game.box[i].y][game.box[i].x - 1] == '#')) ||
            ((game.map[game.box[i].y - 1][game.box[i].x] == '#') &&
            (game.map[game.box[i].y][game.box[i].x - 1] == '#')) ||
            ((game.map[game.box[i].y][game.box[i].x + 1] == '#') &&
            (game.map[game.box[i].y + 1][game.box[i].x] == '#')) ||
            ((game.map[game.box[i].y - 1][game.box[i].x] == '#') &&
            (game.map[game.box[i].y][game.box[i].x + 1] == '#'))) {
            test = 1;
            continue;
        } else
            test = -1;
    }
    if (test == 1)
        exit(1);
}

soko testing_box(soko game)
{
    for (int i = 0 ; i < game.nb_store ; i++) {
        if (game.map[game.store[i].y][game.store[i].x] == ' ')
            game.map[game.store[i].y][game.store[i].x] = 'O';
    }
    return game;
}
