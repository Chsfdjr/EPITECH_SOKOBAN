/*
** EPITECH PROJECT, 2022
** mouv sokoban
** File description:
** ftc
*/

#include "include/sokoban.h"

soko keyboard(soko game, int ch)
{
    if (ch == KEY_UP)
        game = keyup(game);
    if (ch == KEY_DOWN)
        game = keydown(game);
    if (ch == KEY_RIGHT)
        game = keyright(game);
    if (ch == KEY_LEFT)
        game = keyleft(game);
    return game;
}

soko keyup(soko game)
{
    int x = game.player.x;
    int y = game.player.y;
    int X = 0;
    char **map = game.map;
    if ((map[y - 1][x] == ' ') || (map[y - 1][x] == 'O')) {
        map[y - 1][x] = 'P';
        map[y][x] = ' ';
        game.player = (player){x, y - 1};
    }
    if (map[y - 1][x] == 'X') {
        if ((map[y - 2][x] == ' ') || (map[y - 2][x] == 'O')) {
            map[y - 2][x] = 'X';
            map[y - 1][x] = 'P';
            map[y][x] = ' ';
            game.player = (player){x, y - 1};
            X = checkwhichx(game, y - 1, x);
            game.box[X] = (boxes){x, y - 2};
        }
    }
    return game;
}

soko keydown(soko game)
{
    int x = game.player.x;
    int y = game.player.y;
    int X = 0;
    char **map = game.map;
    if ((map[y + 1][x] == ' ') || (map[y + 1][x] == 'O')) {
        map[y + 1][x] = 'P';
        map[y][x] = ' ';
        game.player = (player){x, y + 1};
    }
    if (map[y + 1][x] == 'X') {
        if ((map[y + 2][x] == ' ') || (map[y + 2][x] == 'O')) {
            map[y + 2][x] = 'X';
            map[y + 1][x] = 'P';
            map[y][x] = ' ';
            game.player = (player){x, y + 1};
            X = checkwhichx(game, y + 1, x);
            game.box[X] = (boxes){x, y + 2};
        }
    }
    return game;
}

soko keyleft(soko game)
{
    int x = game.player.x;
    int y = game.player.y;
    int X = 0;
    char **map = game.map;
    if ((map[y][x - 1] == ' ') || (map[y][x - 1] == 'O')) {
        map[y][x - 1] = 'P';
        map[y][x] = ' ';
        game.player = (player){x - 1, y};
    }
    if (map[y][x - 1] == 'X') {
        if ((map[y][x - 2] == ' ') || (map[y][x - 2] == 'O')) {
            map[y][x - 2] = 'X';
            map[y][x - 1] = 'P';
            map[y][x] = ' ';
            game.player = (player){x - 1, y};
            X = checkwhichx(game, y, x - 1);
            game.box[X] = (boxes){x - 2, y};
        }
    }
    return game;
}

soko keyright(soko game)
{
    int x = game.player.x;
    int y = game.player.y;
    int X = 0;
    char **map = game.map;
    if ((map[y][x + 1] == ' ') || (map[y][x + 1] == 'O')) {
        map[y][x + 1] = 'P';
        map[y][x] = ' ';
        game.player = (player){x + 1, y};
    }
    if (map[y][x + 1] == 'X') {
        if ((map[y][x + 2] == ' ') || (map[y][x + 2] == 'O')) {
            map[y][x + 2] = 'X';
            map[y][x + 1] = 'P';
            map[y][x] = ' ';
            game.player = (player){x + 1, y};
            X = checkwhichx(game, y, x + 1);
            game.box[X] = (boxes){x + 2, y};
        }
    }
    return game;
}
