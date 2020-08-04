#include "map.h"

Map *map_generate(int size_x, int size_y, char background)
{
    Map *pMap = malloc(sizeof(Map));
    pMap->pTiles = malloc(sizeof(char) * size_x * size_y);
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

void map_draw(Map *pMap)
{
    for (int y = 0; y < pMap->size_y; y++) {
        for (int x = 0; x < pMap->size_x; x++) {
            mvaddch(x, y, map_get(pMap, x, y));
        }
    }
}

void map_set(Map *pMap, int x, int y, char what)
{
    int pos = y * pMap->size_x + x;
    pMap->pTiles[pos] = what;
}

char map_get(Map *pMap, int x, int y)
{
    int pos = y * pMap->size_x + x;
    return pMap->pTiles[pos];
}

void map_free(Map *pMap)
{
    free(pMap->pTiles);
    free(pMap);
}
