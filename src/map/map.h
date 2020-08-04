#ifndef GUACAMOLE_MAP_H
#define GUACAMOLE_MAP_H

#include <stdlib.h>
#include <ncurses.h>

#include "tile.h"

struct Map {
    Tile *pTiles;
    int size_x;
    int size_y;
} typedef Map;

Map *map_generate(int size_x, int size_y, Tile background);

void map_draw(Map *pMap);

void map_set(Map *pMap, int x, int y, Tile tile);

Tile map_get(Map *pMap, int x, int y);

void map_free(Map *pMap);

#endif //GUACAMOLE_MAP_H
