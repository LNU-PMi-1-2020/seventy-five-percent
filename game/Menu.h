#ifndef SEVENTY_FIVE_PERCENT_MENU_H
#define SEVENTY_FIVE_PERCENT_MENU_H

#include <iostream>
#include <map>
#include <vector>
#include "../utils/Box.h"

using std::string;

class MenuOption {
private:
    size_t id;
    Box *box;
    string text;
    bool hasBorder;
    bool selected = false;

public:
    MenuOption(int id, Box *box, string text, bool hasBorder = true);

    void draw();

    void redraw();

    bool isSelected() const;

    void setSelected(bool isSelected);

    size_t getId() const;
};

class Menu {
private:
    Menu() = default;

public:
    static Menu &get();

    Menu &operator=(Menu &) = delete;

    string currentlyActive;

    std::map<string, std::vector<MenuOption *>> menus;

    void draw();

    void next();

    void prev();

    void unselect();

    size_t getSelected();
};

#endif //SEVENTY_FIVE_PERCENT_MENU_H
