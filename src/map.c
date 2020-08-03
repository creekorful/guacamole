#include "map.h"

Map *map_generate(int row, int column)
{
    Map *map = malloc(sizeof(Map));
    map->tiles = malloc(sizeof(char) * row * column);

    // Todo real stuff
    init_pair(1, COLOR_RED, COLOR_BLACK);

    // Generate basic terrain
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < column; y++) {
            int pos = x * column + y;

            Tile tile = {};
            tile.character = 'A';
            tile.color_pair = 1;

            map->tiles[pos] = tile;
        }
    }

    map->total_row = row;
    map->total_column = column;

    return map;
}

void map_draw(Map *map)
{
    for (int x = 0; x < map->total_row; x++) {
        for (int y = 0; y < map->total_column; y++) {
            int pos = x * map->total_column + y;

            // enable color if any
            int color_pair = map->tiles[pos].color_pair;
            if (color_pair != -1)
                attron(COLOR_PAIR(color_pair));

            // draw the tile
            mvaddch(x, y, map->tiles[pos].character);

            // disable color if any
            if (color_pair != -1)
                attroff(COLOR_PAIR(color_pair));
        }
    }
}

void map_free(Map *map)
{
    free(map->tiles);
    free(map);
}