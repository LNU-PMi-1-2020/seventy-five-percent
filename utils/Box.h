#ifndef SEVENTY_FIVE_PERCENT_BOX_H
#define SEVENTY_FIVE_PERCENT_BOX_H

#include <iostream>
#include <ncurses.h>

using std::string;

class Box {
private:
    string name;
    WINDOW *win = nullptr;
    Box *parent = nullptr;

public:
    explicit Box(const string name);

    Box(const string name, Box *parent, int x, int y, int width, int height);

    Box(const string name, Box *parent, int x, int y, double widthPercent, double heightPercent);

    Box(const string name, Box *parent, double xPercent, double yPercent, int width, int height);

    Box(const string name, Box *parent, double xPercent, double yPercent, double widthPercent, double heightPercent);

    const string &getName() const;

    WINDOW *getWin() const;

    Box *getParent() const;
};


#endif //SEVENTY_FIVE_PERCENT_BOX_H
