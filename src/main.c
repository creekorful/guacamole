#include <ncurses.h>

#include "map/map.h"

int main(int argc, char *argv[])
{
    // Start curses mode
    initscr();
    timeout(0);

    // Enable color support
    start_color();

    // Generate a basic map
    Map *map = map_generate(LINES, COLS, '.');

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
