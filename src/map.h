#ifndef GUACAMOLE_MAP_H
#define GUACAMOLE_MAP_H

#include <stdlib.h>
#include <ncurses.h>

struct Map
{
    char *pTiles;
    int size_x;
    int size_y;
} typedef Map;

Map *map_generate(int size_x, int size_y, char background);

void map_draw(Map *pMap);

void map_set(Map *pMap, int x, int y, char what);

char map_get(Map *pMap, int x, int y);

void map_move(Map *pMap, int src_x, int src_y, int dst_x, int dst_y);

void map_free(Map *pMap);

#endif //GUACAMOLE_MAP_H
