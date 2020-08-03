#include <ncurses.h>

#include "map.h"

int main(int argc, char *argv[])
{
    // Start curses mode
    initscr();

    // Enable color support
    start_color();

    // Generate a basic map
    Map *map = map_generate(LINES, COLS);

    // Draw the map as-is
    map_draw(map);

    // Print it on to the real screen
    refresh();

    // Wait for user input
    getch();

    // Free the map
    map_free(map);

    // End ncurses mode
    endwin();

    return 0;
}
