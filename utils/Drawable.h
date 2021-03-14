#ifndef SEVENTY_FIVE_PERCENT_DRAWABLE_H
#define SEVENTY_FIVE_PERCENT_DRAWABLE_H


#include <ncurses.h>

class Drawable {
protected:
    WINDOW *win = nullptr;

public:
    virtual void draw() = 0;

    WINDOW *getWin() const;
};


#endif //SEVENTY_FIVE_PERCENT_DRAWABLE_H
