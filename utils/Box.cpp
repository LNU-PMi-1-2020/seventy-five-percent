#include "Box.h"

#include <utility>
#include "Printer.h"

Box::Box(string name) : name(std::move(name)), win(stdscr) {}

Box::Box(string name, Box *parent, int x, int y, int width, int height) : name(std::move(name)), parent(parent) {
    win = subwin(parent->getWin(), height, width, y, x);
}

Box::Box(const string &name, Box *parent, int x, int y, double widthPercent, double heightPercent) :
        Box::Box(name, parent, x, y,
                 (int) (getmaxx(parent->getWin()) * widthPercent),
                 (int) (getmaxy(parent->getWin()) * heightPercent)) {}

Box::Box(const string &name, Box *parent, double xPercent, double yPercent, int width, int height) :
        Box::Box(name, parent,
                 (int) (getmaxx(parent->getWin()) * xPercent - width / 2.0),
                 (int) (getmaxy(parent->getWin()) * yPercent - height / 2.0),
                 width, height) {}

Box::Box(const string &name, Box *parent, double xPercent, double yPercent, double widthPercent, double heightPercent) :
        Box::Box(name, parent,
                 (int) (getmaxx(parent->getWin()) * xPercent - (getmaxx(parent->getWin()) * widthPercent) / 2),
                 (int) (getmaxy(parent->getWin()) * yPercent - (getmaxy(parent->getWin()) * heightPercent) / 2),
                 (int) (getmaxx(parent->getWin()) * widthPercent),
                 (int) (getmaxy(parent->getWin()) * heightPercent)) {}

const string &Box::getName() const {
    return name;
}

WINDOW *Box::getWin() const {
    return win;
}

Box *Box::getParent() const {
    return parent;
}

string Box::desc() const {
    int x, y, w, h;
    getmaxyx(win, h, w);
    getbegyx(win, y, x);
    return "Box: " + name + " (" + std::to_string(x) + ", " + std::to_string(y) + ") " + std::to_string(w) + "x" +
           std::to_string(h);
}

void Box::setColor(const int color) const {
    wattron(win, COLOR_PAIR(color));
}

void Box::unsetColor(const int color) const {
    wattroff(win, COLOR_PAIR(color));
}

void Box::centerText(const string &text, bool unicode) {
    Printer::centerText(win, text.c_str(), unicode);
}

void Box::verticalCenterText(int yPos, const string &text, bool unicode) {
    Printer::verticalCenterText(win, yPos, text.c_str(), unicode);
}

void Box::drawBorder(int x, int y) {
    box(win, x, y);
}

void Box::refresh() {
    wrefresh(win);
}
