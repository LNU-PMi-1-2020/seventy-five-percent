#ifndef SEVENTY_FIVE_PERCENT_PRINTER_H
#define SEVENTY_FIVE_PERCENT_PRINTER_H

#include <ncurses.h>
#include <iostream>
#include <cstring>

class Printer {
private:
    Printer() = default;

public:
    static const char *TITLE_LOGO[];
    static const int TITLE_LOGO_COLS;
    static const int TITLE_LOGO_LINES;

    static const int COLOR_YELLOW_BLACK = 1;

    static void init();

    static void close();

    static void initCustomColors();

    static void initColors();

    static short rgb2NC(int rgb);

    static void centerText(WINDOW *win, const char *text);

    static void verticalCenterText(WINDOW *win, int yPos, const char *text);

    static size_t utf8len(const char *const str);
};

#endif //SEVENTY_FIVE_PERCENT_PRINTER_H
