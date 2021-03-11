#include <ncurses.h>
#include <clocale>

#include "utils/Printer.h"

int main() {
    setlocale(LC_ALL, "");

    initscr();
    cbreak();
    noecho();
    curs_set(0);

    if (!has_colors()) {
        Printer::center(stdscr, "No colors support in your terminal, sorry.");
        Printer::verticalCenter(stdscr, LINES - 2, "Press any key to exit");
        getch();
        return -1;
    }

    start_color();

    if (can_change_color()) {
        Printer::initCustomColors();
    }

    WINDOW *titleWin = newwin(Printer::TITLE_LOGO_LINES + 4, Printer::TITLE_LOGO_COLS + 8, 2,
                              COLS / 2 - (Printer::TITLE_LOGO_COLS + 8) / 2);
    refresh();

    box(titleWin, 0, 0);

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    wattron(titleWin, COLOR_PAIR(1));
    for (int i = 0; i < Printer::TITLE_LOGO_LINES; ++i) {
        Printer::verticalCenter(titleWin, i + 2, Printer::TITLE_LOGO[i]);
    }
    wattroff(titleWin, COLOR_PAIR(1));

    wrefresh(titleWin);


    WINDOW *menuText1 = newwin(3, 15, LINES / 3 + 7, COLS / 2 - 8);
    refresh();

    box(menuText1, 0, 0);
    Printer::center(menuText1, "Грати", true);
    wrefresh(menuText1);

    WINDOW *menuText2 = newwin(3, 15, LINES / 3 + 10, COLS / 2 - 8);
    refresh();

    box(menuText2, 0, 0);
    Printer::center(menuText2, "Вийти", true);
    wrefresh(menuText2);

    getch();
    endwin();
}
