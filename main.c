#include <ncurses.h>

int main(int argc, char *argv[])
{
    // Start curses mode
    initscr();

    // Print Hello World
    printw("Hello World !!!");

    // Print it on to the real screen
    refresh();

    // Wait for user input
    getch();

    // End ncurses mode
    endwin();

    return 0;
}
