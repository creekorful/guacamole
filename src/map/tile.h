#ifndef GUACAMOLE_TILE_H
#define GUACAMOLE_TILE_H

struct Tile {
    char character;
    int color_pair;
} typedef Tile;

Tile tile_new(char character, int color_pair);

#endif //GUACAMOLE_TILE_H
