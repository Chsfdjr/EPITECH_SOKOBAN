/*
** EPITECH PROJECT, 2022
** soko obj
** File description:
** d
*/

#include "include/sokoban.h"

int checkwhichx(soko game, int y_1, int x_1)
{
    char **map = game.map;

    for (int i = 0 ; i < game.nb_box ; i++) {
        if (y_1 == game.box[i].y && x_1 == game.box[i].x)
            return i;
    }
}

soko allocate_coordinate(soko game, char **map, int y)
{
    int x = 0;
    int O = 0;
    int X = 0;

    for (int i = 0 ; i < y ; i++) {
        O = count_obj(map[i], O, 'O');
        X = count_obj(map[i], X, 'X');
    }
    game.store = malloc(sizeof(store) * O + 1);
    game.box = malloc(sizeof(boxes) * X + 1);
    game.nb_store = O - 1;
    game.nb_box = X - 1;
    return game;
}

int check_obj(char c, char obj)
{
    int p = -1;
    if (c == obj)
        p = 1;
    return p;
}

soko check_all_obj(soko game, int y)
{
    int O = game.nb_store;
    int X = game.nb_box;
    char **map = game.map;

    for (int i = 0 ; map[y][i] != '\0' ; i++) {
        if (check_obj(map[y][i], 'P') > 0) {
            game.player = (player){i, y};
        }
        if (check_obj(map[y][i], 'O') > 0) {
            game.store[O] = (store){i, y};
            O--;
        }
        if (check_obj(map[y][i], 'X') > 0) {
            game.box[X] = (boxes){i, y};
            X--;
        }
        game.nb_store = O;
        game.nb_box = X;
    }
    return game;
}

int count_obj(char *buffer, int nb_obj, char obj)
{
    for (int i = 0 ; buffer[i] != '\0' ; i++) {
        if (buffer[i] == obj)
            nb_obj++;
    }
    return nb_obj;
}
