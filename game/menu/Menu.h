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

    Menu(const Menu &) = delete;

    string currentlyActive;

    std::map<string, std::vector<MenuOption *>> menus;

    void draw();

    void next(bool ignoreESC);

    void prev(bool ignoreESC);

    void unselect();

    size_t getSelected();

    void handleMenu(bool isHorizontal = false, bool ignoreESC = true);
};

#endif //SEVENTY_FIVE_PERCENT_MENU_H
