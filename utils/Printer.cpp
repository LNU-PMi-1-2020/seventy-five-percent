#include "Printer.h"
#include <clocale>

const char *Printer::TITLE_LOGO[] = {
        R"($$$$$$$$\ $$$$$$$\  $$\   $$\ )",
        R"(\____$$  |$$  ____| \__| $$  |)",
        R"(    $$  / $$ |          $$  / )",
        R"(   $$  /  $$$$$$$\     $$  /  )",
        R"(  $$  /   \_____$$\   $$  /   )",
        R"( $$  /    $$\   $$ | $$  /    )",
        R"($$  /     \$$$$$$  |$$  / $$\ )",
        R"(\__/       \______/ \__/  \__|)"
};
const int Printer::TITLE_LOGO_LINES = sizeof(Printer::TITLE_LOGO) / sizeof(*Printer::TITLE_LOGO);
const int Printer::TITLE_LOGO_COLS = strlen(*Printer::TITLE_LOGO);

void Printer::initCustomColors() {
    init_color(COLOR_BLACK, rgb2NC(40), rgb2NC(40), rgb2NC(40));
    init_color(COLOR_RED, rgb2NC(255), rgb2NC(0), rgb2NC(0));
    init_color(COLOR_GREEN, rgb2NC(0), rgb2NC(255), rgb2NC(0));
    init_color(COLOR_YELLOW, rgb2NC(255), rgb2NC(255), rgb2NC(0));
    init_color(COLOR_BLUE, rgb2NC(0), rgb2NC(0), rgb2NC(255));
    init_color(COLOR_MAGENTA, rgb2NC(255), rgb2NC(0), rgb2NC(255));
    init_color(COLOR_CYAN, rgb2NC(0), rgb2NC(255), rgb2NC(255));
    init_color(COLOR_WHITE, rgb2NC(240), rgb2NC(240), rgb2NC(240));

    init_pair(-1, COLOR_WHITE, COLOR_BLACK);
}

short Printer::rgb2NC(int rgb) {
    if (rgb < 0 || rgb > 255) {
        throw std::invalid_argument("RGB color must be from 0 to 255");
    }
    return short(double(rgb) * 3.90625);
}

void Printer::center(WINDOW *win, const char *text, bool unicode) {
    int xMax = getmaxx(win);
    int yMax = getmaxy(win);

    int len = int(strlen(text)) / (unicode ? 2 : 1);

    int yPos = yMax / 2;
    int xPos = (xMax - len) / 2;

    mvwprintw(win, yPos, xPos, text);
}

void Printer::verticalCenter(WINDOW *win, int yPos, const char *text) {
    int len = strlen(text);

    int xMax = getmaxx(win);
    int xPos = xMax / 2 - len / 2;

    mvwprintw(win, yPos, xPos, text);
}

void Printer::init() {
    setlocale(LC_ALL, "");

    initscr();
    cbreak();
    noecho();
    curs_set(0);

    if (!has_colors()) {
        Printer::center(stdscr, "No colors support in your terminal, sorry.");
        Printer::verticalCenter(stdscr, LINES - 2, "Press any key to exit");
        getch();
        exit(1);
    }

    start_color();

    if (can_change_color()) {
        Printer::initCustomColors();
    }
}

void Printer::close() {
    endwin();
}