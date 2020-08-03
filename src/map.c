#include "map.h"

Map *map_generate(int column, int row)
{
    Map *map = malloc(sizeof(Map));
    map->tiles = malloc(sizeof(char) * column * row);

    // Todo real stuff
    init_pair(1, COLOR_RED, COLOR_BLACK);

    // Generate basic terrain
    for (int x = 0; x < column; x++) {
        for (int y = 0; y < row; y++) {
            int pos = x * column + y;
            map->tiles[pos] = 'A';
        }
    }

    map->total_row = row;
    map->total_column = column;

    return map;
}

void map_draw(Map *map)
{
    for (int x = 0; x < map->total_column; x++) {
        for (int y = 0; y < map->total_row; y++) {
            int pos = x * map->total_column + y;

            // draw the tile
            mvaddch(x, y, map->tiles[pos]);
        }
    }
}

void map_free(Map *map)
{
    free(map->tiles);
    free(map);
}