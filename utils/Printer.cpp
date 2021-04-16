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

void Printer::centerText(WINDOW *win, const char *text) {
    int xMax = getmaxx(win);
    int yMax = getmaxy(win);

    int len = utf8len(text);

    int yPos = yMax / 2;
    int xPos = (xMax - len) / 2;

    mvwprintw(win, yPos, xPos, text);
}

void Printer::verticalCenterText(WINDOW *win, int yPos, const char *text) {
    int len = utf8len(text);

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
    keypad(stdscr, true);
    set_escdelay(0);

    if (LINES < 32 || COLS < 108) {
        centerText(stdscr, "Your terminal should be at least 108x32, sorry.");
        verticalCenterText(stdscr, LINES - 2, "Press any key to exit");
        getch();
        exit(1);
    }

    if (!has_colors()) {
        centerText(stdscr, "No colors support in your terminal, sorry.");
        verticalCenterText(stdscr, LINES - 2, "Press any key to exit");
        getch();
        exit(1);
    }

    start_color();

    if (can_change_color()) {
        initCustomColors();
    }

    initColors();
}

void Printer::close() {
    endwin();
}

void Printer::initColors() {
    init_pair(COLOR_YELLOW_BLACK, COLOR_YELLOW, COLOR_BLACK);
}

size_t Printer::utf8len(const char *const str) {
    size_t len = 0;
    unsigned char c = str[0];
    for (size_t i = 1; c != 0; ++len, ++i) {
        if ((c & 0x80)) {
            if (c < 0xC0)
                return 0;
            c >>= 4;
            if (c == 12)
                c++;
            i += c - 12;
        }
        c = str[i];
    }
    return len;
}
