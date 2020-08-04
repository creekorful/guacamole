#ifndef GUACAMOLE_TILE_H
#define GUACAMOLE_TILE_H

#include <ncurses.h>

struct Tile {
    chtype character;
    int color_pair;
} typedef Tile;

Tile tile_new(chtype character, int color_pair);

#endif //GUACAMOLE_TILE_H
