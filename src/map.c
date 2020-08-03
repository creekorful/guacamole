#include "map.h"

Map *map_generate(int row, int column)
{
    Map *map = malloc(sizeof(Map));
    map->tiles = malloc(sizeof(char) * row * column);

    // Generate basic terrain
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < column; y++) {
            int pos = x * column + y;
            map->tiles[pos] = 'A';
        }
    }

    map->tiles[0] = 'M';
    map->tiles[1] = 'C';

    map->total_row = row;
    map->total_column = column;

    return map;
}

void map_draw(Map *map)
{
    for (int x = 0; x < map->total_row; x++) {
        for (int y = 0; y < map->total_column; y++) {
            int pos = x * map->total_column + y;
            mvaddch(x, y, map->tiles[pos]);
        }
    }
}

void map_free(Map *map)
{
    free(map->tiles);
    free(map);
}