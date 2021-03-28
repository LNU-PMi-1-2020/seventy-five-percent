#include "Game.h"
#include <ncurses.h>
#include "../utils/Printer.h"

void Game::init() {
    Printer::init();
//    boxs["main"] = new Box("main");
}

void Game::stop() {
    Printer::close();
}

void Game::run() {
//    boxs["title"] = new Box("title", boxs["name"], Printer::TITLE_LOGO_COLS + 8, Printer::TITLE_LOGO_LINES + 4, )

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
}