#include <ncurses.h>

int main(int argc, char *argv[])
{
    // Start curses mode
    initscr();

    // Enable color support
    start_color();

    // Create default color pair
    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    // Bind color attributes
    attron(COLOR_PAIR(1));

    // Draw something
    for (int x = 0; x < COLS; x++) {
        for (int y = 0; y < LINES; y++) {
            mvaddch(y, x, 'A');
        }
    }

    // Disable color attributes
    attroff(COLOR_PAIR(1));

    // Print it on to the real screen
    refresh();

    // Wait for user input
    getch();

    // End ncurses mode
    endwin();

    return 0;
}
