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
    explicit Box(string name);

    Box(string name, Box *parent, int x, int y, int width, int height);

    Box(const string &name, Box *parent, int x, int y, double widthPercent, double heightPercent);

    Box(const string &name, Box *parent, double xPercent, double yPercent, int width, int height);

    Box(const string &name, Box *parent, double xPercent, double yPercent, double widthPercent, double heightPercent);

    const string &getName() const;

    WINDOW *getWin() const;

    Box *getParent() const;

    void setColor(int color, bool is) const;

    void setStandout(bool is) const;

    string desc() const;

    void text(const string &text, int x = 0, int y = 0);

    void centerText(const string &text);

    void verticalCenterText(int yPos, const string &text);

    void drawBorder(int x = 0, int y = 0);

    void refresh();

    int getWidth() const;

    int getHeight() const;
};


#endif //SEVENTY_FIVE_PERCENT_BOX_H
