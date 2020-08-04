#include <ncurses.h>

#include "map/map.h"

int main(int argc, char *argv[]) {
    // Start curses mode
    initscr();
    timeout(0);

    // Enable color support
    start_color();

    // Generate a basic map
    Map *map = map_generate(LINES, COLS, '.');

    // Create a character
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    map_set(map, 0, 0, tile_new('A' | A_BOLD, 2));

    while ((getch()) != 'q') {
        map_draw(map);

        // Print on the real screen
        refresh();
    }

    // Cleanup
    map_free(map);
    endwin();

    return 0;
}
