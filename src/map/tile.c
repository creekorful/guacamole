#include "tile.h"

Tile tile_new(chtype character, int color_pair) {
    Tile result;
    result.character = character;
    result.color_pair = color_pair;

    return result;
}
