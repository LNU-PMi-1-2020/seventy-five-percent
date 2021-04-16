#ifndef SEVENTY_FIVE_PERCENT_MENU_H
#define SEVENTY_FIVE_PERCENT_MENU_H

#include <iostream>
#include <map>
#include <vector>
#include "../../utils/Box.h"
#include "MenuOption.h"

using std::string;

class Menu {
private:
    Menu() = default;

public:
    typedef void (*handler)();

    static Menu &get();

    Menu &operator=(Menu &) = delete;

    string currentlyActive;

    std::map<string, std::vector<MenuOption *>> menus;

    void draw();

    void next();

    void prev();

    void unselect();

    size_t getSelected();

    size_t handleMenu(bool isHorizontal = false);
};

#endif //SEVENTY_FIVE_PERCENT_MENU_H
