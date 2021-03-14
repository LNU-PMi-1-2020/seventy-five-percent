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

    static void initCustomColors();

    static short rgb2NC(int rgb);

    static void center(WINDOW *win, const char *text, bool unicode = false);

    static void verticalCenter(WINDOW *win, int yPos, const char *text);
};


#endif //SEVENTY_FIVE_PERCENT_PRINTER_H
