#ifndef GUACAMOLE_MAP_H
#define GUACAMOLE_MAP_H

#include <stdlib.h>
#include <ncurses.h>

struct Tile
{
    char character;
    int color_pair;
} typedef Tile;

struct Map
{
    Tile *tiles;
    unsigned short total_row;
    unsigned short total_column;
} typedef Map;

Map *map_generate(int row, int column);

void map_draw(Map *map);

void map_free(Map *map);

#endif //GUACAMOLE_MAP_H
