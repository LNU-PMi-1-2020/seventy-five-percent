#ifndef SEVENTY_FIVE_PERCENT_ESC_MENU_OPTION_H
#define SEVENTY_FIVE_PERCENT_ESC_MENU_OPTION_H

#include "MenuOption.h"

class FuncMenuOption : public MenuOption {
public:
    explicit FuncMenuOption(void (*onPress)()) {
        f = onPress;
    }

    void draw() override {}

    void redraw() override {}
};

#endif //SEVENTY_FIVE_PERCENT_ESC_MENU_OPTION_H
