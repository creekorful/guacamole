#include "map.h"

Map *map_generate(int size_x, int size_y, Tile background) {
    Map *pMap = malloc(sizeof(Map));
    pMap->pTiles = malloc(sizeof(Tile) * size_x * size_y);
    pMap->size_x = size_x;
    pMap->size_y = size_y;

    // Generate basic terrain
    for (int y = 0; y < size_y; y++) {
        for (int x = 0; x < size_x; x++) {
            map_set(pMap, x, y, background);
        }
    }

    return pMap;
}

void map_draw(Map *pMap) {
    for (int y = 0; y < pMap->size_y; y++) {
        for (int x = 0; x < pMap->size_x; x++) {
            Tile tile = map_get(pMap, x, y);

            if (tile.color_pair != -1)
                attron(COLOR_PAIR(tile.color_pair));

            mvaddch(x, y, tile.character);

            if (tile.color_pair != -1)
                attroff(COLOR_PAIR(tile.color_pair));
        }
    }
}

void map_set(Map *pMap, int x, int y, Tile tile) {
    int pos = y * pMap->size_x + x;
    pMap->pTiles[pos] = tile;
}

Tile map_get(Map *pMap, int x, int y) {
    int pos = y * pMap->size_x + x;
    return pMap->pTiles[pos];
}

void map_free(Map *pMap) {
    free(pMap->pTiles);
    free(pMap);
}
