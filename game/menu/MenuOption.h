#ifndef SEVENTY_FIVE_PERCENT_MENU_OPTION_H
#define SEVENTY_FIVE_PERCENT_MENU_OPTION_H

#include <iostream>
#include "../../utils/Box.h"

using std::string;

class MenuOption {
public:
    virtual void draw() = 0;

    virtual void redraw() = 0;

    virtual bool isSelected() const = 0;

    virtual void setSelected(bool isSelected) = 0;
};

#endif //SEVENTY_FIVE_PERCENT_MENU_OPTION_H
