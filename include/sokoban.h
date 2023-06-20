/*
** EPITECH PROJECT, 2022
** header
** File description:
** pswap
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_
    #include <stdlib.h>
    #include <ncurses.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <signal.h>

typedef struct defplayer {
    int x;
    int y;
} player ;

typedef struct defbox {
    int x;
    int y;
} boxes ;

typedef struct defstore {
    int x;
    int y;
} store ;

typedef struct defsoko {
    player player;
    boxes *box;
    store *store;
    char **map;
    int nb_box;
    int nb_store;
} soko ;

void free_struct(soko game);
int count_obj(char *buffer, int nb_obj, char obj);
int my_strcmp(char const *s1 , char const *s2);
int put_in_map(char *buffer, int longer);
void it_is_map(int fd, int size);
char **createmapfrombuffer(char *buffer, int y);
void *makepartofbuffer(char *map, char *buffer, int j);
int count_largeur(char *buffer);
int popup(soko game, int y);
soko all_test(soko game, int y);
void display_map(char **map, int y);
void testing_loose(soko game, int y);
soko testing_box(soko game);
void testing_end(soko game, int y);
int count_longer(char *buffer, int longer);
soko allocate_coordinate(soko game, char **map, int y);
soko coordinate(char **map, int y);
soko keyboard(soko game, int ch);
soko keyup(soko game);
int checkwhichx(soko game, int y_1, int x_1);
soko keydown(soko game);
soko keyright(soko game);
soko check_all_obj(soko game, int y);
soko keyleft(soko game);
int ch_test(int ch);
int tlc (soko game, int test, int i);
int trc (soko game, int test, int i);
int blc (soko game, int test, int i);
int brc (soko game, int test, int i);
#endif
