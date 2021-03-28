#include "Box.h"

#include <utility>

Box::Box(const string name) : name(name), win(stdscr) {}

Box::Box(string name, Box *parent, int x, int y, int width, int height) : name(std::move(name)), parent(parent) {
    win = subwin(parent->getWin(), height, width, y, x);
}

Box::Box(const string name, Box *parent, int x, int y, double widthPercent, double heightPercent) :
        Box::Box(name, parent, x, y, (int) (getmaxx(parent->getWin()) * widthPercent),
                 (int) (getmaxy(parent->getWin()) * heightPercent)) {}

Box::Box(const string name, Box *parent, double xPercent, double yPercent, int width, int height) :
        Box::Box(name, parent, (int) (getbegx(parent->getWin()) * xPercent),
                 (int) (getbegy(parent->getWin()) * yPercent),
                 width, height) {}

Box::Box(const string name, Box *parent, double xPercent, double yPercent, double widthPercent, double heightPercent) :
        Box::Box(name, parent, (int) (getbegx(parent->getWin()) * xPercent),
                 (int) (getbegy(parent->getWin()) * yPercent), (int) (getmaxx(parent->getWin()) * widthPercent),
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
