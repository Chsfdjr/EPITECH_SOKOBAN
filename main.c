/*
** EPITECH PROJECT, 2022
** main myhunter
** File description:
** eh
*/

#include "include/sokoban.h"

int sokoban_h(void)
{
    char const *filepath = "sokoban_h";
    struct stat desc;
    int rd;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &desc);
    int size = desc.st_size;
    char buffer[size];

    rd = read(fd, buffer, size);
    close(fd);
    buffer[rd] = '\0';
    write(1, buffer, size);
}

int sokoban(char *filepath)
{
    struct stat desc;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &desc);
    int size = desc.st_size;

    if (fd < 0) {
        write(2, "Not a file\n", 12);
        exit(84);
    } else
        it_is_map(fd,size);
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 2 || ac > 2) {
        write(2, "input error : try -h\n", 22);
        return 84;
    }
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] != 'h') {
            write(2, "input error : try -h\n", 22);
            return 84;
        }
        if (my_strcmp(av[1], "-h") == 0) {
            sokoban_h();
            return 0;
        } else {
            sokoban(av[1]);
        }
    }
}
