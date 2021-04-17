#ifndef SEVENTY_FIVE_PERCENT_MENU_OPTION_H
#define SEVENTY_FIVE_PERCENT_MENU_OPTION_H

#include <iostream>
#include "../../utils/Box.h"

using std::string;

class MenuOption {
protected:
    void (*f)() = nullptr;

    bool selected = false;

public:
    virtual void draw() = 0;

    virtual void redraw() = 0;

    bool isSelected() const {
        return selected;
    };

    void setSelected(bool isSelected) {
        selected = isSelected;
    };

    void onPress() {
        f();
    };
};

#endif //SEVENTY_FIVE_PERCENT_MENU_OPTION_H
